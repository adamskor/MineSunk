#include "World.hpp"

World::World(sf::Vector3f startPosition){
  settings = new Settings();
  window = new sf::RenderWindow(sf::VideoMode(settings->resolution.x, settings->resolution.y), "SFML window",sf::Style::Fullscreen);
  //sf::Mouse::setPosition(sf::Vector2i(960, 540), *window);
  //window->setMouseCursorGrabbed(true);
  camera = std::make_shared<Camera>(startPosition, settings);
  eh = std::make_unique<EventHandler>(camera, window);
  for (int i = 0; i < 10; i++){
    blocks.push_back(std::make_unique<Block>(sf::Vector3f(0, i, 0), camera));
    blocks.push_back(std::make_unique<Block>(sf::Vector3f(1, 1, i), camera));
  }
  blocks.push_back(std::make_unique<Block>(sf::Vector3f(0, 0, 0), camera));



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
       //if (event.type == sf::Event){
        eh->HandleEvent(event);

       //}

   }
   // Clear the whole window before rendering a new frame
   window->clear();
   // Draw some graphical entities
   camera->Render(window);
   for (size_t i = 0; i < blocks.size(); i++){
     blocks[i]->OnRender(window);
   }
   //blocks[1]->OnRender(window);
   // End the current frame and display its contents on screen
   window->display();
}
}
