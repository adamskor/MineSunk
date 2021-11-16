#include "Block.hpp"
#include <iostream>
#include <cmath>

#define PI 3.14159265

Block::Block(sf::Vector3f initPosition, std::shared_ptr<Camera> initCamera){
  camera_ptr = initCamera;
  position = initPosition;
  vertices.push_back(sf::Vector3f(position.x    , position.y    , position.z));
  vertices.push_back(sf::Vector3f(position.x + 1, position.y    , position.z));
  vertices.push_back(sf::Vector3f(position.x + 1, position.y    , position.z + 1));
  vertices.push_back(sf::Vector3f(position.x    , position.y    , position.z + 1));
  vertices.push_back(sf::Vector3f(position.x    , position.y + 1, position.z));
  vertices.push_back(sf::Vector3f(position.x + 1, position.y + 1, position.z));
  vertices.push_back(sf::Vector3f(position.x + 1, position.y + 1, position.z + 1));
  vertices.push_back(sf::Vector3f(position.x    , position.y + 1, position.z + 1));
  faceNormals.push_back(sf::Vector3f(1,0,0));
  faceNormals.push_back(sf::Vector3f(-1,0,0));
  faceNormals.push_back(sf::Vector3f(0,1,0));
  faceNormals.push_back(sf::Vector3f(0,-1,0));
  faceNormals.push_back(sf::Vector3f(0,0,1));
  faceNormals.push_back(sf::Vector3f(0,0,-1));
  auto f0 = std::make_shared<sf::ConvexShape>(4);
  auto f1 = std::make_shared<sf::ConvexShape>(4);
  auto f2 = std::make_shared<sf::ConvexShape>(4);
  f0->setFillColor(sf::Color::Green);
  f0->setOutlineColor(sf::Color::Red);
  f0->setOutlineThickness(1);
  f1->setFillColor(sf::Color::Green);
  f1->setOutlineColor(sf::Color::Red);
  f1->setOutlineThickness(1);
  f2->setFillColor(sf::Color::Green);
  f2->setOutlineColor(sf::Color::Red);
  f2->setOutlineThickness(1);
  faces.push_back(f0);
  faces.push_back(f1);
  faces.push_back(f2);
};

void print(sf::Vector2f vec){
  std::cout << vec.x << "  " << vec.y << std::endl;
}

void Block::OnRender(sf::RenderWindow* window){
  activeFaces.clear();
  for (size_t i = 0; i < vertices.size(); i++){
    distanceVertice = camera_ptr->DistanceToCam(vertices[i]);
    if (distanceVertice < startDistance){
      startDistance = distanceVertice;
      nearestVertice = i;
    }
  }

  if (startDistance > 100){
    return;
  }

  Scr_v0 = camera_ptr->MapCoordinateToPoint(vertices[0]);
  Scr_v1 = camera_ptr->MapCoordinateToPoint(vertices[1]);
  Scr_v2 = camera_ptr->MapCoordinateToPoint(vertices[2]);
  Scr_v3 = camera_ptr->MapCoordinateToPoint(vertices[3]);
  Scr_v4 = camera_ptr->MapCoordinateToPoint(vertices[4]);
  Scr_v5 = camera_ptr->MapCoordinateToPoint(vertices[5]);
  Scr_v6 = camera_ptr->MapCoordinateToPoint(vertices[6]);
  Scr_v7 = camera_ptr->MapCoordinateToPoint(vertices[7]);

  switch(nearestVertice){
    case 0:
    {
      faces[0]->setPoint(0, Scr_v0);
      faces[0]->setPoint(1, Scr_v3);
      faces[0]->setPoint(2, Scr_v7);
      faces[0]->setPoint(3, Scr_v4);

      faces[1]->setPoint(0, Scr_v0);
      faces[1]->setPoint(1, Scr_v3);
      faces[1]->setPoint(2, Scr_v2);
      faces[1]->setPoint(3, Scr_v1);

      faces[2]->setPoint(0, Scr_v0);
      faces[2]->setPoint(1, Scr_v4);
      faces[2]->setPoint(2, Scr_v5);
      faces[2]->setPoint(3, Scr_v1);

      break;
    }
    case 1:
    {
      faces[0]->setPoint(0, Scr_v1);
      faces[0]->setPoint(1, Scr_v2);
      faces[0]->setPoint(2, Scr_v6);
      faces[0]->setPoint(3, Scr_v5);

      faces[1]->setPoint(0, Scr_v0);
      faces[1]->setPoint(1, Scr_v3);
      faces[1]->setPoint(2, Scr_v2);
      faces[1]->setPoint(3, Scr_v1);

      faces[2]->setPoint(0, Scr_v0);
      faces[2]->setPoint(1, Scr_v4);
      faces[2]->setPoint(2, Scr_v5);
      faces[2]->setPoint(3, Scr_v1);

      break;
    }
    case 2:
    {
      faces[0]->setPoint(0, Scr_v1);
      faces[0]->setPoint(1, Scr_v2);
      faces[0]->setPoint(2, Scr_v6);
      faces[0]->setPoint(3, Scr_v5);

      faces[1]->setPoint(0, Scr_v0);
      faces[1]->setPoint(1, Scr_v3);
      faces[1]->setPoint(2, Scr_v2);
      faces[1]->setPoint(3, Scr_v1);

      faces[2]->setPoint(0, Scr_v3);
      faces[2]->setPoint(1, Scr_v7);
      faces[2]->setPoint(2, Scr_v6);
      faces[2]->setPoint(3, Scr_v2);
      
      break;
    }
    case 3:
    {
      faces[0]->setPoint(0, Scr_v0);
      faces[0]->setPoint(1, Scr_v3);
      faces[0]->setPoint(2, Scr_v7);
      faces[0]->setPoint(3, Scr_v4);

      faces[1]->setPoint(0, Scr_v0);
      faces[1]->setPoint(1, Scr_v3);
      faces[1]->setPoint(2, Scr_v2);
      faces[1]->setPoint(3, Scr_v1);

      faces[2]->setPoint(0, Scr_v3);
      faces[2]->setPoint(1, Scr_v7);
      faces[2]->setPoint(2, Scr_v6);
      faces[2]->setPoint(3, Scr_v2);

      break;
    }
    case 4:
    {
      faces[0]->setPoint(0, Scr_v0);
      faces[0]->setPoint(1, Scr_v3);
      faces[0]->setPoint(2, Scr_v7);
      faces[0]->setPoint(3, Scr_v4);

      faces[1]->setPoint(0, Scr_v4);
      faces[1]->setPoint(1, Scr_v7);
      faces[1]->setPoint(2, Scr_v6);
      faces[1]->setPoint(3, Scr_v5);

      faces[2]->setPoint(0, Scr_v0);
      faces[2]->setPoint(1, Scr_v4);
      faces[2]->setPoint(2, Scr_v5);
      faces[2]->setPoint(3, Scr_v1);

      break;
    }
    case 5:
    {
      faces[0]->setPoint(0, Scr_v1);
      faces[0]->setPoint(1, Scr_v2);
      faces[0]->setPoint(2, Scr_v6);
      faces[0]->setPoint(3, Scr_v5);

      faces[1]->setPoint(0, Scr_v4);
      faces[1]->setPoint(1, Scr_v7);
      faces[1]->setPoint(2, Scr_v6);
      faces[1]->setPoint(3, Scr_v5);

      faces[2]->setPoint(0, Scr_v0);
      faces[2]->setPoint(1, Scr_v4);
      faces[2]->setPoint(2, Scr_v5);
      faces[2]->setPoint(3, Scr_v1);

      break;
    }
    case 6:
    {
      faces[0]->setPoint(0, Scr_v1);
      faces[0]->setPoint(1, Scr_v2);
      faces[0]->setPoint(2, Scr_v6);
      faces[0]->setPoint(3, Scr_v5);

      faces[1]->setPoint(0, Scr_v4);
      faces[1]->setPoint(1, Scr_v7);
      faces[1]->setPoint(2, Scr_v6);
      faces[1]->setPoint(3, Scr_v5);

      faces[2]->setPoint(0, Scr_v3);
      faces[2]->setPoint(1, Scr_v7);
      faces[2]->setPoint(2, Scr_v6);
      faces[2]->setPoint(3, Scr_v2);

      break;
    }
    case 7:
    {
      faces[0]->setPoint(0, Scr_v0);
      faces[0]->setPoint(1, Scr_v3);
      faces[0]->setPoint(2, Scr_v7);
      faces[0]->setPoint(3, Scr_v4);

      faces[1]->setPoint(0, Scr_v4);
      faces[1]->setPoint(1, Scr_v7);
      faces[1]->setPoint(2, Scr_v6);
      faces[1]->setPoint(3, Scr_v5);

      faces[2]->setPoint(0, Scr_v3);
      faces[2]->setPoint(1, Scr_v7);
      faces[2]->setPoint(2, Scr_v6);
      faces[2]->setPoint(3, Scr_v2);

      break;
    }
  }
  startDistance = 101;

  auto f0v1tov0 = faces[0]->getPoint(1) - faces[0]->getPoint(0);
  auto f0v1tov2 = faces[0]->getPoint(1) - faces[0]->getPoint(2);
  auto f0v2tov1 = faces[0]->getPoint(2) - faces[0]->getPoint(1);
  auto f0v2tov3 = faces[0]->getPoint(2) - faces[0]->getPoint(3);

  auto f1v1tov0 = faces[1]->getPoint(1) - faces[1]->getPoint(0);
  auto f1v1tov2 = faces[1]->getPoint(1) - faces[1]->getPoint(2);
  auto f1v2tov1 = faces[1]->getPoint(2) - faces[1]->getPoint(1);
  auto f1v2tov3 = faces[1]->getPoint(2) - faces[1]->getPoint(3);

  auto f2v1tov0 = faces[2]->getPoint(1) - faces[2]->getPoint(0);
  auto f2v1tov2 = faces[2]->getPoint(1) - faces[2]->getPoint(2);
  auto f2v2tov1 = faces[2]->getPoint(2) - faces[2]->getPoint(1);
  auto f2v2tov3 = faces[2]->getPoint(2) - faces[2]->getPoint(3);

  if(camera_ptr->AngleABVec2(f0v1tov0, f0v1tov2) > 3 &&
     camera_ptr->AngleABVec2(f0v2tov1, f0v2tov3) > 3)
  {
       window->draw(*faces[0]);
  }
  if(camera_ptr->AngleABVec2(f1v1tov0, f1v1tov2) > 3 &&
     camera_ptr->AngleABVec2(f1v2tov1, f1v2tov3) > 3)
  {
       window->draw(*faces[1]);
  }
  if(camera_ptr->AngleABVec2(f2v1tov0, f2v1tov2) > 3 &&
     camera_ptr->AngleABVec2(f2v2tov1, f2v2tov3) > 3)
  {
       window->draw(*faces[2]);
  }
}
