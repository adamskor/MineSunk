#pragma once
#include "SFML/Graphics.hpp"
#include <memory>


class Block {
public:
  Block() = default;
  Block(sf::Vector3f initPosition){
    auto v1 = sf::Vector3f{10, 0,10};
    auto v2 = sf::Vector3f{11, 0,10};
    auto v3 = sf::Vector3f{11, 0,11};
    auto v4 = sf::Vector3f{10, 0,11};

    auto v5 = sf::Vector3f{0,-5,0};
    auto v6 = sf::Vector3f{0,1,0};
    Scr_v0 = pointToScreen(v1,v5,v6);
    Scr_v1 = pointToScreen(v2, v5,v6);
    Scr_v2 = pointToScreen(v3,v5,v6);
    Scr_v3 = pointToScreen(v4, v5,v6);
  };
  ~Block() = default;
public:
  void OnRender(sf::RenderWindow* window);
  void OnUpdate(const sf::Vector3f& cameraPosition,
                const sf::Vector3f& cameraDirection);
  void OnEvent();
  sf::Vector2f pointToScreen(const sf::Vector3f& point,
                             const sf::Vector3f& cameraPosition,
                             const sf::Vector3f& cameraDirection);

private:
  /*
  Face 0: norm = (1,0,0), vertices: 1, 2, 6, 5
  Face 1: norm = (-1,0,0), vertices: 0, 3, 7, 4
  Face 2: norm = (0,1,0), vertices: 4, 7, 6, 5
  Face 3: norm = (0,-1,0), vertices: 0, 3, 2, 1
  Face 4: norm = (0,0,1), vertices: 3, 7, 6, 2
  Face 5: norm = (0,0,-1), vertices: 0, 4, 5, 1
  */
  sf::Vector3f v0, v1, v2, v3, v4, v5, v6, v7;
  sf::Vector3f norm_f0{1,0,0}, norm_f1{-1,0,0}, norm_f2{0,1,0},
               norm_f3{0,-1,0}, norm_f4{0,0,1}, norm_f5{0,0,-1};
  sf::Vector2f Scr_v0, Scr_v1, Scr_v2, Scr_v3, Scr_v4, Scr_v5;

};
