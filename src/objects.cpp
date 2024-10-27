#include "objects.h"
    
void Objects::init(){

    platformTexture_1.loadFromFile("images/pngwing.png");
    platformTexture_2.loadFromFile("images/pngwingCut.png");

    sf::Sprite platformSprite_1, platformSprite_2;
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

std::vector <sf::Sprite> Objects::draw(){
    return platforms;
}

