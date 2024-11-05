#include "objects.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
 
Objects::Objects(){


    herotextureL.loadFromFile("images/HeroL.png");
    herotextureR.loadFromFile("images/HeroR.png");

    herosprite.setTexture(herotextureR);
    herosprite.setPosition(900, 735);

    herosprite.setScale(sf::Vector2f(0.125f, 0.125f)); // размер спрайта

    }

void Objects::init(){

    platformTexture_1.loadFromFile("images/pngwing.png");
    platformTexture_2.loadFromFile("images/pngwingCut.png");

    platformSprite_1.setTexture(platformTexture_1);
    platformSprite_2.setTexture(platformTexture_2);

    platformSprite_1.setScale(sf::Vector2f(0.4f, 0.4f)); 
    platformSprite_2.setScale(sf::Vector2f(0.4f, 0.4f)); 

    for(int i = 0; i < 20; i++){
        platformSprite_1.setPosition(i*150,800);
        platforms.push_back(platformSprite_1);

        platformSprite_2.setPosition(i*150,950);
        platforms.push_back(platformSprite_2);

    }

}

std::vector <sf::Sprite> Objects::getSprite(){
    
    return platforms;

}

sf::Sprite Objects::getHeroSprite(){

    return herosprite;

}

sf::Texture * Objects::getTexture(){

    sf::Texture * arr = new sf::Texture[2];

    arr[0] = herotextureL;
    arr[1] = herotextureR;

    return arr;

}
