#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

class Objects{

public:

//  interact

    sf::Texture heroTextureL;
    sf::Texture heroTextureR;

    sf::Sprite heroSprite;

    //

    sf::Texture enemyTextureL;
    sf::Texture enemyTextureR;

    sf::Sprite enemySprite;

    //

    sf::Texture bulletTextureL;
    sf::Texture bulletTextureR;

    sf::Sprite bulletSprite;

//  static

    sf::Texture platformTexture_1, platformTexture_2;
    sf::Sprite platformSprite_1, platformSprite_2;

    std::vector <sf::Sprite> platforms;

public:

    Objects();

    std::map <std::string,sf::Sprite> getInteractSprite();
    std::map <std::string,sf::Texture> getInteractTexture();
    
    std::map <std::string, std::vector <sf::Sprite>> getStaticSprite(); // статические объекты (где не нужно работать с текстурами

};


