#include "resource.h"
#include "SFML/Graphics/Texture.hpp"

void Resource::loud(sf::Texture texture){
    texture.loadFromFile("images/pngwing.png");
    texture.loadFromFile("images/pngwingCut.png");

}
