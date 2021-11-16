#include "Camera.hpp"

#define PI 3.14159265
#define DEGTORAD 0.0174532
#define RADTODEG 180/PI


Camera::Camera(sf::Vector3f initPosition, Settings* initSettings)
{
  position = initPosition;
  settings = initSettings;
  screenDistance = 5;
  horizontalFOV = settings->horizontalFOV;
  verticalFOV = settings->verticalFOV;
  screenWidthPix = settings->resolution.x;
  screenHeightPix = settings->resolution.y;
  renderDistance = settings->renderDistance;
  screenWidth = tan(horizontalFOV*DEGTORAD)*screenDistance;
  screenHeight = tan(verticalFOV*DEGTORAD)*screenDistance;
  screenCenter = position + screenNormal*screenDistance;
  theta = 90.0;
  roe = 90.0;
  if (!font.loadFromFile("MineSunk/arial.ttf"))
  {
    std::cout << "Failed to load font!" << std::endl;
  }
  info.setFont(font);
  info.setCharacterSize(24);
  info.setFillColor(sf::Color::White);



  std::cout << screenWidth << " " << screenHeight << std::endl;


  square = sf::ConvexShape(4);
  square.setFillColor(sf::Color::Blue);
  square.setOutlineColor(sf::Color::Red);
  square.setOutlineThickness(4);
  verticesSquare.push_back(sf::Vector3f(-1,-1,0));
  verticesSquare.push_back(sf::Vector3f(1,-1,0));
  verticesSquare.push_back(sf::Vector3f(1,1,0));
  verticesSquare.push_back(sf::Vector3f(-1,1,0));

  UpdateGeometry();
}

void Camera::Print(sf::Vector3f vec){
  std::cout << "Print Vector: (" << vec.x << ", "
            << vec.y << ", " << vec.z << ")" << std::endl;
}

sf::Vector2f Camera::MapCoordinateToPoint(const sf::Vector3f& vec)
{
  auto camToPoint = vec - position;
  //Print(camToPoint);
  auto dotNorVec = Dot(screenNormal, camToPoint);
  if (dotNorVec == 0)
  {
    return sf::Vector2f(screenWidthPix/2,screenHeightPix/2);
  }
  //if (dotNorVec < 0)
  //{
  //  return sf::Vector2f(-1,-1);
  //}
  auto d = Dot((screenCenter - vec), screenNormal)/dotNorVec;
  auto p = vec + camToPoint*d;
  auto centerToP = p - screenCenter;
  auto cToPonHB = ProjectAonB(centerToP, screenHorizontalBasis);
  auto cToPonVB = ProjectAonB(centerToP, screenVerticalBasis);
  auto sizeOnHB = Size(cToPonHB);
  auto sizeOnVB = Size(cToPonVB);
  auto WithHB = Dot(cToPonHB, screenHorizontalBasis);
  auto WithVB = Dot(cToPonVB, screenVerticalBasis);
  std::cout << WithHB << std::endl;
  std::cout << WithVB << std::endl;
  if (WithHB > 0 && WithVB > 0){
    auto xPixel = screenWidthPix/2 + (sizeOnHB/screenWidth)*screenWidthPix/2;
    auto yPixel = screenHeightPix/2 + (sizeOnVB/screenHeight)*screenHeightPix/2;
    if (dotNorVec < 0)
    {
      return sf::Vector2f(-xPixel,-yPixel);
    }
    return sf::Vector2f(xPixel,yPixel);
  }
  if (WithHB <= 0 && WithVB > 0){
    auto xPixel = screenWidthPix/2 - (sizeOnHB/screenWidth)*screenWidthPix/2;
    auto yPixel = screenHeightPix/2 + (sizeOnVB/screenHeight)*screenHeightPix/2;
    if (dotNorVec < 0)
    {
      return sf::Vector2f(-xPixel,-yPixel);
    }
    return sf::Vector2f(xPixel,yPixel);
  }
  if (WithHB <= 0 && WithVB <= 0){
    auto xPixel = screenWidthPix/2 - (sizeOnHB/screenWidth)*screenWidthPix/2;
    auto yPixel = screenHeightPix/2 - (sizeOnVB/screenHeight)*screenHeightPix/2;
    if (dotNorVec < 0)
    {
      return sf::Vector2f(-xPixel,-yPixel);
    }
    return sf::Vector2f(xPixel,yPixel);
  }
  if (WithHB > 0 && WithVB <= 0){
    auto xPixel = screenWidthPix/2 + (sizeOnHB/screenWidth)*screenWidthPix/2;
    auto yPixel = screenHeightPix/2 - (sizeOnVB/screenHeight)*screenHeightPix/2;
    if (dotNorVec < 0)
    {
      return sf::Vector2f(-xPixel,-yPixel);
    }
    return sf::Vector2f(xPixel,yPixel);
  }
  return sf::Vector2f(-1,-1);


}

bool Camera::isInView(const sf::Vector3f& vec)
{
  return true;
}


void Camera::UpdateGeometry()
{
  float x = static_cast<float>(cos(roe*DEGTORAD)*sin(theta*DEGTORAD));
  float y = static_cast<float>(sin(roe*DEGTORAD)*sin(theta*DEGTORAD));
  float z = static_cast<float>(cos(theta*DEGTORAD));
  sf::Vector3f temp = sf::Vector3f{position.x + x,
                                   position.y + y,
                                   position.z + z};
  screenNormal = temp - position;
  screenCenter = position + screenNormal*screenDistance;
  if(screenNormal.x < 0 && screenNormal.y < 0){
    screenHorizontalBasis = sf::Vector3f(screenNormal.y/screenNormal.x, 1, 0);
  }
  if(screenNormal.x < 0){
    screenHorizontalBasis = sf::Vector3f(screenNormal.y/screenNormal.x, -1, 0);
  }
  else{
    screenHorizontalBasis = sf::Vector3f(-screenNormal.y/screenNormal.x, 1, 0);
  }

  screenVerticalBasis = sf::Vector3f
  (
    screenNormal.y*screenHorizontalBasis.z - screenNormal.z*screenHorizontalBasis.y,
    screenNormal.z*screenHorizontalBasis.x - screenNormal.x*screenHorizontalBasis.z,
    screenNormal.x*screenHorizontalBasis.y - screenNormal.y*screenHorizontalBasis.x
  );
  screenNormal = Normalize(screenNormal);
  screenHorizontalBasis = Normalize(screenHorizontalBasis);
  screenVerticalBasis = -Normalize(screenVerticalBasis);
  std::cout << "NormalVec " << screenNormal.x << " " << screenNormal.y << " " << screenNormal.z << std::endl;
  std::cout << "HBVec " << screenHorizontalBasis.x << " " << screenHorizontalBasis.y << " " << screenHorizontalBasis.z << std::endl;
  std::cout << "VBVec " << screenVerticalBasis.x << " " << screenVerticalBasis.y << " " << screenVerticalBasis.z << std::endl;
  std::cout << "Position " << position.x << " " << position.y << " " << position.z << std::endl;
  infoText = "Position: (" + std::to_string(position.x) + ", " + std::to_string(position.y) +
              ", " + std::to_string(position.z) + ") \n" +  "Direction: (" + std::to_string(screenNormal.x) + ", " + std::to_string(screenNormal.y) +
                          ", " + std::to_string(screenNormal.z) + ")";

  info.setString(infoText);
  for (size_t i = 0; i < verticesSquare.size(); i++){
    square.setPoint(i, MapCoordinateToPoint(verticesSquare[i]));
  }

}

void Camera::Render(sf::RenderWindow* window){
  window->draw(square);
  window->draw(info);
}

float Camera::Size(const sf::Vector3f& vec){
  return sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
}

sf::Vector3f Camera::Normalize(const sf::Vector3f& vec, float scale)
{
  float norm = Size(vec);
  if (norm){
    return sf::Vector3f(vec.x/(norm*scale), vec.y/(norm*scale), vec.z/(norm*scale));
  }
  return sf::Vector3f(0,0,0);
}

float Camera::DistanceToCam(const sf::Vector3f& vec)
{
  sf::Vector3f tmp = position - vec;
  return Size(tmp);
}

sf::Vector3f Camera::ProjectAonB(const sf::Vector3f& A, const sf::Vector3f& B)
{
  float dotB = Dot(B,B);
  if (dotB){
    float scale = Dot(A,B)/dotB;
    return sf::Vector3f(scale*B.x, scale*B.y, scale*B.z);
  }
  return sf::Vector3f(0,0,0);
}

float Camera::Dot(const sf::Vector3f& A, const sf::Vector3f& B)
{
  return (A.x*B.x + A.y*B.y + A.z*B.z);
}

float Camera::AngleAB(const sf::Vector3f& A, const sf::Vector3f& B)
{
  auto size_A = Size(A);
  auto size_B = Size(B);
  if(size_A != 0 && size_B != 0){
    return acos(Dot(A,B)/(size_A*size_B))*RADTODEG;
  }
  return 0;
}


void Camera::TiltUp()
{
  if (theta - 1 > 0){
    theta -= 1;
    UpdateGeometry();
  }
}

void Camera::TiltDown()
{
  if (theta + 1 < 180){
    theta += 1;
    UpdateGeometry();
  }
}

void Camera::RotateRight()
{
  if (roe < 180){
    roe += 1;
  }
  else{
    roe = -180;
  }
  UpdateGeometry();
}

void Camera::RotateLeft()
{
  if (roe > -180){
    roe -= 1;
  }
  else{
    roe = 180;
  }
  UpdateGeometry();
}

void Camera::MoveForward()
{
  position += Normalize(screenNormal, 10);
  UpdateGeometry();
}

void Camera::MoveBackwards()
{
  position -= Normalize(screenNormal, 10);
  UpdateGeometry();
}

void Camera::MoveRight()
{
  position += Normalize(screenHorizontalBasis, 10);
  UpdateGeometry();
}

void Camera::MoveLeft()
{
  position -= Normalize(screenHorizontalBasis, 10);
  UpdateGeometry();
}
