#include "EventHandler.hpp"

EventHandler::EventHandler(std::shared_ptr<Camera> camera, sf::RenderWindow* i_window) :
camera_ptr{camera}, window{i_window}
{
  hasFocus = false;
  mouseSensitivity = 1;
}


void EventHandler::HandleEvent(const sf::Event& event)
{
  if (event.type == sf::Event::MouseMoved){
    MouseMoveEvent(event);
  }
  if (event.type == sf::Event::KeyPressed){
    KeyboardEvent(event);
  }
  if (event.type == sf::Event::LostFocus || event.type == sf::Event::GainedFocus){
    FocusEvent(event);
  }

}


void EventHandler::MouseMoveEvent(const sf::Event& event)
{

}

void EventHandler::KeyboardEvent(const sf::Event& event)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    camera_ptr->MoveLeft();
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    camera_ptr->MoveRight();
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    camera_ptr->MoveForward();
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    camera_ptr->MoveBackwards();
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    camera_ptr->TiltDown();
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
  {
    camera_ptr->TiltUp();
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    camera_ptr->RotateRight();
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    camera_ptr->RotateLeft();
  }
}

void EventHandler::FocusEvent(const sf::Event& event)
{
  if (event.type == sf::Event::LostFocus)
    hasFocus = false;
  if (event.type == sf::Event::GainedFocus)
    hasFocus = true;
  std::cout << hasFocus << std::endl;
}
