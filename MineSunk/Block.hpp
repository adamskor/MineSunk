#pragma once
#include "SFML/Graphics.hpp"
#include "Camera.hpp"
#include <memory>
#include <algorithm>

class Block {
public:
  Block() = default;
  Block(sf::Vector3f initPosition, std::shared_ptr<Camera> initCamera);
  ~Block() = default;
public:
  void OnRender(sf::RenderWindow* window);
  void OnUpdate();
  void OnEvent();
public:
  void setHiddenFaces(const std::vector<int>& hidFaces);
  void setVisible(bool vis);
private:
  /*
  Face 0: norm = (1,0,0), vertices: 1, 2, 6, 5
  Face 1: norm = (-1,0,0), vertices: 0, 3, 7, 4
  Face 2: norm = (0,1,0), vertices: 4, 7, 6, 5
  Face 3: norm = (0,-1,0), vertices: 0, 3, 2, 1
  Face 4: norm = (0,0,1), vertices: 3, 7, 6, 2
  Face 5: norm = (0,0,-1), vertices: 0, 4, 5, 1
  */
  std::vector<sf::Vector3f> vertices;
  std::vector<int> activeFaces;
  sf::Vector2f Scr_v0, Scr_v1, Scr_v2, Scr_v3, Scr_v4, Scr_v5, Scr_v6, Scr_v7;
  std::vector<std::shared_ptr<sf::ConvexShape>> faces;
  std::vector<int> hiddenFaces;
  int nearestVertice;
  float distanceVertice;
  float startDistance = 101;
private:
  sf::Vector3f position;
  bool visible{true};
private:
  std::shared_ptr<Camera> camera_ptr;


};
