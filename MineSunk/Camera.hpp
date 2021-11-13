#pragma once
#include "SFML/Graphics.hpp"

class Camera{
public:
  Camera(sf::Vector3f i_position){
    position = i_position;
    direction = sf::Vector3f(0, 1, 0);
  };
  sf::Vector3f getPosition(){
    return position;
  };
  sf::Vector3f getDirection(){
    return direction;
  };
private:
  sf::Vector3f position;
  sf::Vector3f direction;

};
