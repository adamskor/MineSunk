#pragma once
#include "SFML/Graphics.hpp"
#include <memory>

struct Indices {
  int f1, f2, f3;
};

struct BlockFace {
public:
  BlockFace() = default;
  BlockFace(sf::Vector3f i_normal, sf::Vector3f i_v0, sf::Vector3f i_v1,
                                   sf::Vector3f i_v2, sf::Vector3f i_v3);

public: //In 3d-Space
  bool visible{true};
  sf::Vector3f normal;
  std::unique_ptr<sf::ConvexShape> face;
  std::unique_ptr<sf::RectangleShape> test;
  sf::Vector3f v0;
  sf::Vector3f v1;
  sf::Vector3f v2;
  sf::Vector3f v3;
public: //In 2d-Projection Space
  void Render(sf::RenderWindow* window, const sf::Vector3f& cameraPosition,
              const sf::Vector3f& cameraDirection);
  void calcProjection(const sf::Vector3f& cameraPosition,
                      const sf::Vector3f& cameraDirection);
  sf::Vector2f v0_2d;
  sf::Vector2f v1_2d;
  sf::Vector2f v2_2d;
  sf::Vector2f v3_2d;
};


class Block {
public:
  Block(sf::Vector3f i_position);
  Indices getIndices(sf::Vector3f cameraPosition);
  void Render(sf::RenderWindow* window, const sf::Vector3f cameraPosition,
                                        const sf::Vector3f cameraDirection);
private:
  std::vector<std::unique_ptr<BlockFace>> faces;
  const int size = 1;
  sf::Vector3f position;
};
