#pragma once
#include "SFML/Graphics.hpp"
#include "Settings.hpp"
#include <vector>
#include <cmath>
#include <iostream>



class Camera
{
public:
  Camera() = default;
  Camera(sf::Vector3f initPosition, Settings* initSettings);
public:
  void Render(sf::RenderWindow* window);
public:
  sf::Vector2f MapCoordinateToPoint(const sf::Vector3f& vec);
  bool isInView(const sf::Vector3f& vec);
public:
  void Print(sf::Vector3f vec);
public:
  void UpdateGeometry();
public:
  sf::Vector3f Normalize(const sf::Vector3f& vec, float scale = 1);
  sf::Vector3f ProjectAonB(const sf::Vector3f& A, const sf::Vector3f& B);
  float Size(const sf::Vector3f& vec);
  float DistanceToCam(const sf::Vector3f& vec);
  float Dot(const sf::Vector3f& A, const sf::Vector3f& B);
  float AngleAB(const sf::Vector3f& A, const sf::Vector3f& B);
public:
  void TiltUp();
  void TiltDown();
  void RotateRight();
  void RotateLeft();
  void MoveForward();
  void MoveBackwards();
  void MoveRight();
  void MoveLeft();
private:
  sf::Vector3f position;
  sf::Vector3f screenCenter;
  sf::Vector3f screenNormal;
  sf::Vector3f screenHorizontalBasis;
  sf::Vector3f screenVerticalBasis;
private:
  double theta;
  double roe;
private:
  sf::Font font;
  sf::Text info;
  std::string infoText;
private:
  float screenDistance;
  int screenWidthPix;
  int screenHeightPix;
  float screenWidth;
  float screenHeight;
  float horizontalFOV;
  float verticalFOV;
  float renderDistance;
  sf::ConvexShape square;
  sf::ConvexShape floor;
  std::vector<sf::Vector3f> verticesSquare;
private:
  Settings* settings;

};
