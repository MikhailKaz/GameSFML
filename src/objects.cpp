#include "objects.h"

Objects::Objects(){

//  interact

    heroTextureL.loadFromFile("images/HeroL.png");
    heroTextureR.loadFromFile("images/HeroR.png");

    heroSprite.setTexture(heroTextureR);
    heroSprite.setPosition(900,735);

    heroSprite.setScale(sf::Vector2f(0.125f, 0.125f)); // размер спрайта

//

    enemyTextureL.loadFromFile("images/enemyL.png");
    enemyTextureR.loadFromFile("images/enemyR.png");

    enemySprite.setTexture(enemyTextureR);
    enemySprite.setPosition(300,735);

    enemySprite.setScale(sf::Vector2f(0.5f, 0.5f)); // размер спрайта

//
 
    bulletTextureL.loadFromFile("images/bulletL.png");
    bulletTextureR.loadFromFile("images/bulletR.png");
    
    bulletSprite.setTexture(bulletTextureR);

//  static

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

std::map <std::string, std::vector <sf::Sprite>> Objects::getStaticSprite(){
    
    std::map <std::string, std::vector <sf::Sprite>> dictStacicSprite;

    dictStacicSprite ["platforms"] = platforms;

    return dictStacicSprite;

}

std::map <std::string, sf::Sprite> Objects::getInteractSprite(){

    std::map <std::string, sf::Sprite> dictInteractSprite;
    
    dictInteractSprite ["heroSprite"] = heroSprite;
    dictInteractSprite ["enemySprite"] = enemySprite;
    dictInteractSprite ["bulletSprite"] = bulletSprite;

    return dictInteractSprite;

}

 std::map <std::string,sf::Texture> Objects::getInteractTexture(){

    std::map <std::string,sf::Texture> dictInteractTexture;
    
    dictInteractTexture ["heroTextureL"] = heroTextureL;
    dictInteractTexture ["heroTextureR"] = heroTextureR;

    dictInteractTexture ["enemyTextureL"] = enemyTextureL;
    dictInteractTexture ["enemyTextureR"] = enemyTextureR;

    dictInteractTexture ["bulletTextureL"] = bulletTextureL;
    dictInteractTexture ["bulletTextureR"] = bulletTextureR;
    
    return dictInteractTexture;

}
