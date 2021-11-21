#include "World.hpp"

World::World(sf::Vector3f startPosition){
  settings = new Settings();
  window = new sf::RenderWindow(sf::VideoMode(settings->resolution.x, settings->resolution.y), "SFML window");
  //sf::Mouse::setPosition(sf::Vector2i(960, 540), *window);
  //window->setMouseCursorGrabbed(true);
  camera = std::make_shared<Camera>(startPosition, settings);
  eh = std::make_unique<EventHandler>(camera, window);
  //auto inPos = sf::Vector3f(0,0,0);
  //chunk = std::make_unique<Chunk>(inPos, camera);
  Test();




}

void World::Test()
{
   testobjects.push_back(std::make_unique<sf::ConvexShape>(3));
   testobjects.push_back(std::make_unique<sf::ConvexShape>(3));
   testobjects.push_back(std::make_unique<sf::ConvexShape>(3));
   testobjects.push_back(std::make_unique<sf::ConvexShape>(3));
   testobjects[0]->setFillColor(sf::Color::Red);
   testobjects[1]->setFillColor(sf::Color::Green);
   testobjects[2]->setFillColor(sf::Color::Blue);
   testobjects[3]->setFillColor(sf::Color::Yellow);


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

   //chunk->OnRender(window);
   camera->Render(window,timeMS);
   auto tri1v1 = sf::Vector3f(0,0,0);
   auto tri1v2 = sf::Vector3f(0,1,0.5);
   auto tri1v3 = sf::Vector3f(0,0,5);
   auto p1 = camera->MapCoordinateToPoint(tri1v1);
   auto p2 = camera->MapCoordinateToPoint(tri1v2);
   auto p3 = camera->MapCoordinateToPoint(tri1v3);
   testobjects[0]->setPoint(0, p1);
   testobjects[0]->setPoint(1, p2);
   testobjects[0]->setPoint(2, p3);
   window->draw(*testobjects[0]);
   tri1v1 = sf::Vector3f(0,0,0);
   tri1v2 = sf::Vector3f(1,0,0.5);
   tri1v3 = sf::Vector3f(0,0,1);
   p1 = camera->MapCoordinateToPoint(tri1v1);
   p2 = camera->MapCoordinateToPoint(tri1v2);
   p3 = camera->MapCoordinateToPoint(tri1v3);
   testobjects[1]->setPoint(0, p1);
   testobjects[1]->setPoint(1, p2);
   testobjects[1]->setPoint(2, p3);
   window->draw(*testobjects[1]);
   tri1v1 = sf::Vector3f(2,0,0);
   tri1v2 = sf::Vector3f(1,0,0.5);
   tri1v3 = sf::Vector3f(2,0,1);
   p1 = camera->MapCoordinateToPoint(tri1v1);
   p2 = camera->MapCoordinateToPoint(tri1v2);
   p3 = camera->MapCoordinateToPoint(tri1v3);
   testobjects[2]->setPoint(0, p1);
   testobjects[2]->setPoint(1, p2);
   testobjects[2]->setPoint(2, p3);
   window->draw(*testobjects[2]);
   tri1v1 = sf::Vector3f(0,0,0);
   tri1v2 = sf::Vector3f(0,-1,0.5);
   tri1v3 = sf::Vector3f(0,0,1);
   p1 = camera->MapCoordinateToPoint(tri1v1);
   p2 = camera->MapCoordinateToPoint(tri1v2);
   p3 = camera->MapCoordinateToPoint(tri1v3);
   testobjects[3]->setPoint(0, p1);
   testobjects[3]->setPoint(1, p2);
   testobjects[3]->setPoint(2, p3);
   window->draw(*testobjects[3]);
   //blocks[1]->OnRender(window);
   // End the current frame and display its contents on screen
   window->display();
   sf::Time time = clock.getElapsedTime();
   timeMS = time.asMilliseconds();
}
}
