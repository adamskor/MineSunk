#include "World.hpp"
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"


int main(){

  World world = World(sf::Vector3f(-2,-2,0));
  world.run();
/*
  sf::Vector3f start = sf::Vector3f(0,-5,0);
  Camera camera(start);
  sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 450), "SFML window");
// Limit the framerate to 60 frames per second (this step is optional)
window->setFramerateLimit(60);
// The main loop - ends as soon as the window is closed
while (window->isOpen())
{
   // Event processing
   sf::Event event;
   while (window->pollEvent(event))
   {
       // Request for closing the window
       if (event.type == sf::Event::Closed)
           window->close();
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
       {
         camera.MoveLeft();
       }
       else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
       {
         camera.MoveRight();
       }
       else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
       {
         camera.MoveForward();
       }
       else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
       {
         camera.MoveBackwards();
       }
       else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
       {
         camera.TiltDown();
       }
       else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
       {
         camera.TiltUp();
       }
       else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
       {
         camera.RotateRight();
       }
       else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
       {
         camera.RotateLeft();
       }



   }
   // Clear the whole window before rendering a new frame
   window->clear();
   // Draw some graphical entities
   camera.Render(window);
   // End the current frame and display its contents on screen
   window->display();
}
*/
}
