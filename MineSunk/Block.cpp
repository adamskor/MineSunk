#include "Block.hpp"
#include <iostream>
#include <cmath>

#define PI 3.14159265

BlockFace::BlockFace(sf::Vector3f i_normal, sf::Vector3f i_v0, sf::Vector3f i_v1, sf::Vector3f i_v2, sf::Vector3f i_v3){
  face = std::make_unique<sf::ConvexShape>(4);
  face->setOutlineColor(sf::Color::Blue);
  face->setOutlineThickness(3);
  face->setFillColor(sf::Color::Green);
  normal = i_normal;
  v0 = i_v0;
  v1 = i_v1;
  v2 = i_v2;
  v3 = i_v3;
}

void BlockFace::calcProjection(const sf::Vector3f& cameraPosition,
                               const sf::Vector3f& cameraDirection){

  auto cam_to_v0 = v0 - cameraPosition;
  auto angleXYv0 = (180/PI)*acos((cameraDirection.x * cam_to_v0.x + cameraDirection.y * cam_to_v0.y)/(
                       sqrt(pow(cameraDirection.x, 2) + pow(cameraDirection.y, 2)) *
                       sqrt(pow(cam_to_v0.x, 2) + pow(cam_to_v0.y, 2))));
  auto cam_to_v1 = v1 - cameraPosition;
  auto angleXYv1 = (180/PI)*acos((cameraDirection.x * cam_to_v1.x + cameraDirection.y * cam_to_v1.y)/(
                         sqrt(pow(cameraDirection.x, 2) + pow(cameraDirection.y, 2)) *
                         sqrt(pow(cam_to_v1.x, 2) + pow(cam_to_v1.y, 2))));
  auto cam_to_v2 = v2 - cameraPosition;
  auto angleXYv2 = (180/PI)*acos((cameraDirection.x * cam_to_v2.x + cameraDirection.y * cam_to_v2.y)/(
                                              sqrt(pow(cameraDirection.x, 2) + pow(cameraDirection.y, 2)) *
                                              sqrt(pow(cam_to_v2.x, 2) + pow(cam_to_v2.y, 2))));
  auto cam_to_v3 = v3 - cameraPosition;
  auto angleXYv3 = (180/PI)*acos((cameraDirection.x * cam_to_v3.x + cameraDirection.y * cam_to_v3.y)/(
                                                sqrt(pow(cameraDirection.x, 2) + pow(cameraDirection.y, 2)) *
                                                sqrt(pow(cam_to_v3.x, 2) + pow(cam_to_v3.y, 2))));

  std::cout << angleXYv0 << std::endl;
  std::cout << angleXYv1 << std::endl;
  std::cout << angleXYv2 << std::endl;
  std::cout << angleXYv3 << std::endl;

  //auto cam_to_v1 = cameraPosition - v1;
  //auto cam_to_v2 = cameraPosition - v2;
  //auto cam_to_v3 = cameraPosition - v3;




}

void BlockFace::Render(sf::RenderWindow* window,
                       const sf::Vector3f& cameraPosition,
                       const sf::Vector3f& cameraDirection){
  calcProjection(cameraPosition, cameraDirection);
  window->draw(*face);


}

Block::Block(sf::Vector3f i_position){
  position = i_position;
  //faces.push_back(std::make_unique<BlockFace>(sf::Vector3f(0,0,1),
  //  position + sf::Vector3f(0, 0, 1),
  //  position + sf::Vector3f(0, 1, 1),
  //  position + sf::Vector3f(1, 0, 1),
  //  position + sf::Vector3f(1, 1, 1)
  //  ));
  //faces.push_back(std::make_unique<BlockFace>(sf::Vector3f(0,0,-1),
  //  position + sf::Vector3f(0, 0, 0),
  //  position + sf::Vector3f(0, 1, 0),
  //  position + sf::Vector3f(1, 0, 0),
  //  position + sf::Vector3f(1, 1, 0)
  //  ));
  //faces.push_back(std::make_unique<BlockFace>(sf::Vector3f(0,1,0),
  //  position + sf::Vector3f(0, 1, 0),
  //  position + sf::Vector3f(0, 1, 1),
  //  position + sf::Vector3f(1, 1, 0),
  //  position + sf::Vector3f(1, 1, 1)
  //  ));
  faces.push_back(std::make_unique<BlockFace>(sf::Vector3f(0,-1,0),
    position + sf::Vector3f(0, 0, 0),
    position + sf::Vector3f(0, 0, 1),
    position + sf::Vector3f(1, 0, 1),
    position + sf::Vector3f(1, 0, 0)

    ));
  //faces.push_back(std::make_unique<BlockFace>(sf::Vector3f(1,0,0),
  //  position + sf::Vector3f(1, 0, 0),
  //  position + sf::Vector3f(1, 0, 1),
  //  position + sf::Vector3f(1, 1, 0),
  //  position + sf::Vector3f(1, 1, 1)
  //  ));
  //faces.push_back(std::make_unique<BlockFace>(sf::Vector3f(-1,0,0),
  //  position + sf::Vector3f(0, 0, 0),
  //  position + sf::Vector3f(0, 0, 1),
  //  position + sf::Vector3f(0, 1, 0),
  //  position + sf::Vector3f(0, 1, 1)
  //  ));

}



Indices Block::getIndices(sf::Vector3f cameraPosition){
  Indices temp{0,0,0};
  if (position.x - cameraPosition.x > 0){temp.f1 = 5;}
  else{temp.f1 = 4;}
  if (position.y - cameraPosition.y > 0){temp.f2 = 3;}
  else{temp.f2 = 2;}
  if (position.z - cameraPosition.z > 0){temp.f3 = 1;}
  else{temp.f3 = 0;}
  return temp;
}

void Block::Render(sf::RenderWindow* window, const sf::Vector3f cameraPosition,
                                             const sf::Vector3f cameraDirection){
  auto indices = getIndices(cameraPosition);
  //faces[indices.f1]->Render(window, cameraPosition);
  //faces[indices.f2]->Render(window, cameraPosition);
  //faces[indices.f3]->Render(window, cameraPosition);
  faces[0]->Render(window, cameraPosition, cameraDirection);
  //faces[1]->Render(window, cameraPosition, cameraDirection);
  //faces[2]->Render(window, cameraPosition, cameraDirection);
  //faces[3]->Render(window, cameraPosition, cameraDirection);
  //faces[4]->Render(window, cameraPosition, cameraDirection);
  //faces[5]->Render(window, cameraPosition, cameraDirection);
}
