#include "World.hpp"

World::World(sf::Vector3f startPosition){
  window = new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window");
  camera = std::make_unique<Camera>(startPosition);
  blocks.push_back(std::make_unique<Block>(sf::Vector3f(0, 2, 0)));

}

void World::run(){
  while (window->isOpen())
{
   // Event processing
   sf::Event event;
   while (window->pollEvent(event))
   {
       // Request for closing the window
       if (event.type == sf::Event::Closed)
           window->close();
   }
   // Clear the whole window before rendering a new frame
   window->clear();
   // Draw some graphical entities
   blocks[0]->Render(window, camera->getPosition(), camera->getDirection());
   // End the current frame and display its contents on screen
   window->display();
}
}
