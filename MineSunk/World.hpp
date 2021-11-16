#pragma once
#include "Camera.hpp"
#include "Block.hpp"
#include "EventHandler.hpp"
#include "Settings.hpp"
#include "Chunk.hpp"


class World {
public:
  World(sf::Vector3f startPosition);
  void run();
public:
  int timeMS;
private:
  std::unique_ptr<Chunk> chunk;
  std::shared_ptr<Camera> camera;
  std::unique_ptr<EventHandler> eh;
  sf::RenderWindow* window;
  Settings* settings;
};
