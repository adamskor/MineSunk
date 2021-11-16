#include "Settings.hpp"

Settings::Settings()
{
  resolution = sf::Vector2i(1920, 1080);
  aspectRatio = sf::Vector2i(16, 9);
  horizontalFOV = 40;
  verticalFOV = 22.5;
  renderDistance = 100;
  mouseSensitivity = 1;
}
