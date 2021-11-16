#include "Block.hpp"
#include <iostream>
#include <cmath>

#define PI 3.14159265

Block::Block(sf::Vector3f initPosition, std::shared_ptr<Camera> initCamera){
  camera_ptr = initCamera;
  position = initPosition;
  v0 = sf::Vector3f(position.x    , position.y    , position.z);
  v1 = sf::Vector3f(position.x + 1, position.y    , position.z);
  v2 = sf::Vector3f(position.x + 1, position.y    , position.z + 1);
  v3 = sf::Vector3f(position.x    , position.y    , position.z + 1);
  v4 = sf::Vector3f(position.x    , position.y + 1, position.z);
  v5 = sf::Vector3f(position.x + 1, position.y + 1, position.z);
  v6 = sf::Vector3f(position.x + 1, position.y + 1, position.z + 1);
  v7 = sf::Vector3f(position.x    , position.y + 1, position.z + 1);
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
  f0->setOutlineThickness(4);
  f1->setFillColor(sf::Color::Green);
  f1->setOutlineColor(sf::Color::Red);
  f1->setOutlineThickness(4);
  f2->setFillColor(sf::Color::Green);
  f2->setOutlineColor(sf::Color::Red);
  f2->setOutlineThickness(4);
  faces.push_back(f0);
  faces.push_back(f1);
  faces.push_back(f2);
};

void Block::OnRender(sf::RenderWindow* window){
  activeFaces.clear();
  for (size_t i = 0; i < faceNormals.size(); i++){
    if (camera_ptr->Dot(faceNormals[i], camera_ptr->getNormal()) < 0){
      activeFaces.push_back(i);
    }
  }
  std::cout << activeFaces.size() << std::endl;
  for (size_t i = 0; i < activeFaces.size(); i++){

    switch(activeFaces[i]){
      case 0: {
        faces[i]->setPoint(0, camera_ptr->MapCoordinateToPoint(v1));
        faces[i]->setPoint(1, camera_ptr->MapCoordinateToPoint(v2));
        faces[i]->setPoint(2, camera_ptr->MapCoordinateToPoint(v6));
        faces[i]->setPoint(3, camera_ptr->MapCoordinateToPoint(v5));
        std::cout << "Drawing face 0" << std::endl;
        break;
      }
      case 1: {
        faces[i]->setPoint(0, camera_ptr->MapCoordinateToPoint(v0));
        faces[i]->setPoint(1, camera_ptr->MapCoordinateToPoint(v3));
        faces[i]->setPoint(2, camera_ptr->MapCoordinateToPoint(v7));
        faces[i]->setPoint(3, camera_ptr->MapCoordinateToPoint(v4));
        std::cout << "Drawing face 1" << std::endl;
        break;
      }
      case 2: {
        faces[i]->setPoint(0, camera_ptr->MapCoordinateToPoint(v4));
        faces[i]->setPoint(1, camera_ptr->MapCoordinateToPoint(v7));
        faces[i]->setPoint(2, camera_ptr->MapCoordinateToPoint(v6));
        faces[i]->setPoint(3, camera_ptr->MapCoordinateToPoint(v5));
        std::cout << "Drawing face 2" << std::endl;
        break;
      }
      case 3: {
        faces[i]->setPoint(0, camera_ptr->MapCoordinateToPoint(v0));
        faces[i]->setPoint(1, camera_ptr->MapCoordinateToPoint(v3));
        faces[i]->setPoint(2, camera_ptr->MapCoordinateToPoint(v2));
        faces[i]->setPoint(3, camera_ptr->MapCoordinateToPoint(v1));
        std::cout << "Drawing face 3" << std::endl;
        break;
      }
      case 4: {
        faces[i]->setPoint(0, camera_ptr->MapCoordinateToPoint(v3));
        faces[i]->setPoint(1, camera_ptr->MapCoordinateToPoint(v7));
        faces[i]->setPoint(2, camera_ptr->MapCoordinateToPoint(v6));
        faces[i]->setPoint(3, camera_ptr->MapCoordinateToPoint(v2));
        std::cout << "Drawing face 4" << std::endl;
        break;
      }
      case 5: {
        faces[i]->setPoint(0, camera_ptr->MapCoordinateToPoint(v0));
        faces[i]->setPoint(1, camera_ptr->MapCoordinateToPoint(v4));
        faces[i]->setPoint(2, camera_ptr->MapCoordinateToPoint(v5));
        faces[i]->setPoint(3, camera_ptr->MapCoordinateToPoint(v1));
        std::cout << "Drawing face 5" << std::endl;
        break;
      }
    }
  }
  window->draw(*faces[0]);
  window->draw(*faces[1]);
  window->draw(*faces[2]);
}
