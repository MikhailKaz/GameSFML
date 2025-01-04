#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Objects{

public:

// characters

    sf::Texture heroTextureL;
    sf::Texture heroTextureR;

    sf::Sprite heroSprite;

    //

    sf::Texture enemyTextureL;
    sf::Texture enemyTextureR;

    sf::Sprite enemySprite;

//  object

    sf::Texture platformTexture_1, platformTexture_2;
    sf::Sprite platformSprite_1, platformSprite_2;

    std::vector <sf::Sprite> platforms;

public:

    Objects();

    std::vector <sf::Sprite> getSprite();

    std::map <std::string, sf::Sprite> getCharactersSprite();
    std::map <std::string,sf::Texture> getCharactersTexture();

};


