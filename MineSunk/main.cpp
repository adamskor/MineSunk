#include "World.hpp"

int main(){


  auto world = std::make_unique<World>(sf::Vector3f(0,-1,0));
  world->run();


}
