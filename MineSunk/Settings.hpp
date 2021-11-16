#pragma once
#include "SFML/Graphics.hpp"

class Settings
{
public:
  Settings();
public:
  sf::Vector2i resolution;
  sf::Vector2i aspectRatio;
  float horizontalFOV;
  float verticalFOV;
public:
  int renderDistance;
  int mouseSensitivity;

};
