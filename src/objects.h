#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Objects{

public:

    sf::Texture herotextureL;
    sf::Texture herotextureR;

    sf::Sprite herosprite;

    sf::Texture platformTexture_1, platformTexture_2;
    sf::Sprite platformSprite_1, platformSprite_2;

    std::vector <sf::Sprite> platforms;

public:

    Objects();

    std::vector <sf::Sprite> getSprite();
    void init();

    sf::Sprite getHeroSprite();
    sf::Texture * getTexture();

};


