#pragma once
#include "Camera.hpp"
#include "Block.hpp"


class World {
public:
  World(sf::Vector3f startPosition);
  void run();
private:
  std::vector<std::unique_ptr<Block>> blocks;
  std::unique_ptr<Camera> camera;
  sf::RenderWindow* window;
};
