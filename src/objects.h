#include "SFML/Graphics/Sprite.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Objects{

public:
    sf::Texture platformTexture_1, platformTexture_2;
    //sf::Sprite platform;
    std::vector <sf::Sprite> platforms;

public:
    std::vector <sf::Sprite> draw();
    void init();

}; 


