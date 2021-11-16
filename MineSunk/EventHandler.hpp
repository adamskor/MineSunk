#pragma once
#include "SFML/Graphics.hpp"
#include <memory>
#include <iostream>
#include "Camera.hpp"


class EventHandler
{
public:
  EventHandler() = default;
  EventHandler(std::shared_ptr<Camera> camera, sf::RenderWindow* i_window);
  void HandleEvent(const sf::Event& event);
  void MouseMoveEvent(const sf::Event& event);
  void KeyboardEvent(const sf::Event& event);
  void FocusEvent(const sf::Event& event);
private:
  std::shared_ptr<Camera> camera_ptr = nullptr;
  sf::RenderWindow* window;
  int mouseSensitivity;
  bool hasFocus;
};
