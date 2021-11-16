#include "Chunk.hpp"

Chunk::Chunk(const sf::Vector3f& initPosition,
             std::shared_ptr<Camera> camera) :
             position{initPosition},
             size{sf::Vector3f(16,16,16)},
             camera_ptr{camera}
{
  //4096 blocks
  for (int z = 0; z < size.z; z++){
    for (int y = 0; y < size.y; y++){
      for (int x = 0; x < size.x; x++){
        blocks.push_back(std::make_unique<Block>(sf::Vector3f(position.x + x,
                                                              position.y + y,
                                                              position.z + z),
                                                              camera_ptr));
      }
    }
  }
  OnChange();
}

sf::Vector3f Chunk::getBP(int index)
{
  if (index < 0 || index > 4095){
    return sf::Vector3f(position.x - 2,
                        position.y - 2,
                        position.z - 2);
  }
  int ind = index;
  int x = (int)ind%16;
  int y = (int)(ind%256)/16;
  int z = (int)ind/256;
  return sf::Vector3f(x,y,z);
}

void Chunk::OnRender(sf::RenderWindow* window)
{
  for (size_t i = 0; i < blocks.size(); i++)
  {
    blocks[i]->OnRender(window);
  }
}

void Chunk::OnChange()
{
  sf::Vector3f curr;
  sf::Vector3f comp;
  for (size_t i = 0; i < blocks.size(); i++)
  {
    hidFaces.clear();
    curr = getBP(i);
    comp = getBP(i+1);
    if (curr.y == comp.y && curr.z == comp.z)
      hidFaces.push_back(0);
    comp = getBP(i-1);
    if (curr.y == comp.y && curr.z == comp.z)
      hidFaces.push_back(1);
    comp = getBP(i+16);
    if (curr.x == comp.x && curr.z == comp.z)
      hidFaces.push_back(2);
    comp = getBP(i-16);
    if (curr.x == comp.x && curr.z == comp.z)
      hidFaces.push_back(3);
    comp = getBP(i+256);
    if (curr.x == comp.x && curr.y == comp.y)
      hidFaces.push_back(4);
    comp = getBP(i-256);
    if (curr.x == comp.x && curr.y == comp.y)
      hidFaces.push_back(5);
    if (hidFaces.size() == 6){
      blocks[i]->setVisible(false);
    }else{
      blocks[i]->setVisible(true);
      blocks[i]->setHiddenFaces(hidFaces);
    }
  }
}
