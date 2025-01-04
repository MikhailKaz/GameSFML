#include "objects.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <map>

Objects::Objects(){

    heroTextureL.loadFromFile("images/HeroL.png");
    heroTextureR.loadFromFile("images/HeroR.png");

    heroSprite.setTexture(heroTextureR);
    heroSprite.setPosition(900,735);

    heroSprite.setScale(sf::Vector2f(0.125f, 0.125f)); // размер спрайта

    enemyTextureL.loadFromFile("images/enemyL.png");
    enemyTextureR.loadFromFile("images/enemyR.png");

    enemySprite.setTexture(enemyTextureR);
    enemySprite.setPosition(300,735);

    enemySprite.setScale(sf::Vector2f(0.5f, 0.5f)); // размер спрайта
    
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

std::map <std::string, sf::Sprite> Objects::getCharactersSprite(){

    std::map <std::string, sf::Sprite> dictCharactersSprite;
    
    dictCharactersSprite ["heroSprite"] = heroSprite;
    dictCharactersSprite ["enemySprite"] = enemySprite;

    return dictCharactersSprite;

}

 std::map <std::string,sf::Texture> Objects::getCharactersTexture(){

    std::map <std::string,sf::Texture> dictCharactersTexture;
    
    dictCharactersTexture ["heroTextureL"] = heroTextureL;
    dictCharactersTexture ["heroTextureR"] = heroTextureR;

    dictCharactersTexture ["enemyTextureL"] = enemyTextureL;
    dictCharactersTexture ["enemyTextureR"] = enemyTextureR;
    
    return dictCharactersTexture;

}
