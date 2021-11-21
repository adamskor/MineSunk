#include "Chunk.hpp"

Chunk::Chunk(const sf::Vector3f& initPosition,
             std::shared_ptr<Camera> camera) :
             position{initPosition},
             size{sf::Vector3f(2,2,1)},
             camera_ptr{camera}
{
  //4096 blocks
  for (int z = 0; z < size.z; z++){
    for (int x = 0; x < size.x; x++){
      for (int y = 0; y < size.y; y++){
        blocks.push_back(std::make_unique<Block>(sf::Vector3f(position.x + x,
                                                              position.y + y,
                                                              position.z + z),
                                                              camera_ptr));
      }
    }
  }
  n_Blocks = size.x*size.y*size.z - 1;
  x_Size = size.x;
  xy_Size = size.x*size.y;
  OnChange();
}

sf::Vector3f Chunk::getBP(int index)
{
  if (index < 0 || index > n_Blocks){
    return sf::Vector3f(position.x - 2,
                        position.y - 2,
                        position.z - 2);
  }
  int ind = index;

  int x = (int)((ind%xy_Size)/x_Size);
  int y = (int)((ind%xy_Size)%x_Size);
  int z = (int)(ind/xy_Size);
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
    if (curr.x == comp.x && curr.z == comp.z && curr.y == comp.y - 1)
      hidFaces.push_back(2);
    comp = getBP(i-1);
    if (curr.x == comp.x && curr.z == comp.z && curr.y == comp.y + 1)
      hidFaces.push_back(3);
    comp = getBP(i+x_Size);
    if (curr.y == comp.y && curr.z == comp.z && curr.x == comp.x - 1)
      hidFaces.push_back(0);
    comp = getBP(i-x_Size);
    if (curr.y == comp.y && curr.z == comp.z && curr.x == comp.x + 1)
      hidFaces.push_back(1);
    comp = getBP(i+xy_Size);
    if (curr.x == comp.x && curr.y == comp.y && curr.z == comp.z - 1)
      hidFaces.push_back(4);
    comp = getBP(i-xy_Size);
    if (curr.x == comp.x && curr.y == comp.y && curr.z == comp.z + 1)
      hidFaces.push_back(5);
    if (hidFaces.size() == 6){
      blocks[i]->setVisible(false);
    }else{
      blocks[i]->setVisible(true);
      blocks[i]->setHiddenFaces(hidFaces);
    }

  /*
  std::cout << "Block " << i << ": ";
  for (size_t i = 0; i < hidFaces.size(); i++){
    std::cout << hidFaces[i] << " ,";

  }
  std::cout << std::endl;
  std::cout << "x: " << curr.x << " y: " << curr.y<< " z: " << curr.z;
  std::cout << std::endl;
  */
  }
}
