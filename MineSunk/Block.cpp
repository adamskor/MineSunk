#include "Block.hpp"
#include <iostream>
#include <cmath>

#define PI 3.14159265

double dot(sf::Vector3f v1, sf::Vector3f v2){
  return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

sf::Vector2f Block::pointToScreen(const sf::Vector3f& point,
                                  const sf::Vector3f& cameraPosition,
                                  const sf::Vector3f& cameraDirection)
{
  int screenHeight = 600;
  int screenWidth = 800;
  int FOV = 80;
  float screenHeightBlock = 2.07107;
  float screenWidthBlock = 4.1955;
  int camDist = 5;
  sf::Vector3f base1 = sf::Vector3f(1,0,0);
  sf::Vector3f base2 = sf::Vector3f(0,0,1);
  auto v = point - cameraPosition;
  auto projNtoP = sf::Vector3f((dot(cameraDirection, v)/(dot(v, v)))*v.x,
                               (dot(cameraDirection, v)/(dot(v, v)))*v.y,
                               (dot(cameraDirection, v)/(dot(v, v)))*v.z);
  auto s = cameraPosition + sf::Vector3f(camDist*(1/sqrt(dot(cameraDirection, cameraDirection)))*cameraDirection.x,
                                         camDist*(1/sqrt(dot(cameraDirection, cameraDirection)))*cameraDirection.y,
                                         camDist*(1/sqrt(dot(cameraDirection, cameraDirection)))*cameraDirection.z);
  auto i = cameraPosition + projNtoP;
  auto widthPos = base1.x/i.x + base1.y/i.y + base1.z/i.z;
  auto heightPos = base2.x/i.x + base2.y/i.y + base2.z/i.z;
  widthPos = screenWidthBlock/widthPos;
  heightPos = screenHeightBlock/heightPos;
  return sf::Vector2f{(widthPos/screenWidthBlock)*screenWidth,(heightPos/screenHeightBlock)*screenHeight};

}

void Block::OnRender(sf::RenderWindow* window){
  sf::ConvexShape face = sf::ConvexShape{4};
  face.setPoint(0, Scr_v0);
  face.setPoint(1, Scr_v1);
  face.setPoint(2, Scr_v2);
  face.setPoint(3, Scr_v3);
  window->draw(face);
}
