#pragma once
#include "Camera.hpp"
#include "Block.hpp"
#include "EventHandler.hpp"
#include "Settings.hpp"


class World {
public:
  World(sf::Vector3f startPosition);
  void run();
public:

private:
  std::vector<std::unique_ptr<Block>> blocks;
  std::shared_ptr<Camera> camera;
  std::unique_ptr<EventHandler> eh;
  sf::RenderWindow* window;
  Settings* settings;
};
