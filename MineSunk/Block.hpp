#pragma once
#include "SFML/Graphics.hpp"
#include "Camera.hpp"
#include <memory>
#include <algorithm>

class BlockFace;

class Block {
public:
  Block() = default;
  Block(sf::Vector3f initPosition, std::shared_ptr<Camera> initCamera);
  ~Block() = default;

private:
  std::shared_ptr<Camera> camera_ptr;


};

class BlockFace
{
public:
  BlockFace()



};
/*
Face 0: norm = (1,0,0), vertices: 1, 2, 6, 5
Face 1: norm = (-1,0,0), vertices: 0, 3, 7, 4
Face 2: norm = (0,1,0), vertices: 4, 7, 6, 5
Face 3: norm = (0,-1,0), vertices: 0, 3, 2, 1
Face 4: norm = (0,0,1), vertices: 3, 7, 6, 2
Face 5: norm = (0,0,-1), vertices: 0, 4, 5, 1
*/
