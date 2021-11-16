#pragma once
#include "SFML/Graphics.hpp"
#include "Block.hpp"
#include "Camera.hpp"

class Chunk
{
public:
  Chunk() = default;
  Chunk(const sf::Vector3f& initPosition,
        std::shared_ptr<Camera> camera);
  Chunk(const sf::Vector3f& initPosition,
        const std::vector<int>& blocks,
        std::shared_ptr<Camera> camera);
public:
  void OnRender(sf::RenderWindow* window);
  void OnChange();
  sf::Vector3f getBP(int index);
private:
  std::vector<std::unique_ptr<Block>> blocks;
  /*
  Face 0: norm = (1,0,0), vertices: 1, 2, 6, 5
  Face 1: norm = (-1,0,0), vertices: 0, 3, 7, 4
  Face 2: norm = (0,1,0), vertices: 4, 7, 6, 5
  Face 3: norm = (0,-1,0), vertices: 0, 3, 2, 1
  Face 4: norm = (0,0,1), vertices: 3, 7, 6, 2
  Face 5: norm = (0,0,-1), vertices: 0, 4, 5, 1
  */
private:
  const sf::Vector3f size;
  const sf::Vector3f position;
  std::vector<int> hidFaces;
  std::shared_ptr<Camera> camera_ptr;


};
