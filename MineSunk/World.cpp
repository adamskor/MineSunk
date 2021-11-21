#include "World.hpp"

World::World(sf::Vector3f startPosition){
  settings = new Settings();
  window = new sf::RenderWindow(sf::VideoMode(settings->resolution.x, settings->resolution.y), "SFML window",sf::Style::Fullscreen);
  //sf::Mouse::setPosition(sf::Vector2i(960, 540), *window);
  //window->setMouseCursorGrabbed(true);
  camera = std::make_shared<Camera>(startPosition, settings);
  eh = std::make_unique<EventHandler>(camera, window);
  auto inPos = sf::Vector3f(0,0,0);
  chunk = std::make_unique<Chunk>(inPos, camera);




}

void World::run(){

  while (window->isOpen())
{
   sf::Clock clock;
   clock.restart();
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

   chunk->OnRender(window);
   camera->Render(window,timeMS);
   //blocks[1]->OnRender(window);
   // End the current frame and display its contents on screen
   window->display();
   sf::Time time = clock.getElapsedTime();
   timeMS = time.asMilliseconds();
}
}
