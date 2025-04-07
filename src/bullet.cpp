#include "bullet.h"
#include "SFML/Window/Keyboard.hpp"

Bullet::Bullet(){

    bulletTextureL.loadFromFile("images/bulletL.png");
    bulletTextureR.loadFromFile("images/bulletR.png");
    
    bulletSprite.setTexture(bulletTextureR);

    shoot.first = false;
    shoot.second = true;


}

void Bullet::update(sf::View view, std::vector <sf::Event::KeyEvent> pressedKeys, bool directHero, sf::Sprite heroSprite){

    bool noShoot = true; // есть ли Enter в векторе (изначально не стреляем)

    for(auto key : pressedKeys){

        if (key.code == sf::Keyboard::Enter){
            shoot.first = true;
            noShoot = false;
        }
    }

// проверки если Enter не нажата

    if (noShoot){
        shoot.second = true;
        shoot.first = false;
    }


// добавление bullet

    if(shoot.first && shoot.second){ // новое нажатие Enter

        sf::Sprite bulletSprite;

        std::pair <sf::Sprite, bool> bullet;

        if(directHero == 1){
            bulletSprite.setPosition(heroSprite.getPosition().x + 60,heroSprite.getPosition().y + 32);
            bulletSprite.setTexture(bulletTextureR);
        }

        else if(directHero == 0){
            bulletSprite.setPosition(heroSprite.getPosition().x,heroSprite.getPosition().y + 32);
            bulletSprite.setTexture(bulletTextureL);
        }

        bullet.first = bulletSprite;

        bullet.second = directHero;
        
        bulletVecSprite.push_back(bullet); // X/Y/направление
        
        shoot.second = false; // обновится в проверке отжатия клавиш                                                
    } 

// удаление bullet (за пределами экрана)

    for(int i = 0; i < bulletVecSprite.size(); i++){

        if(bulletVecSprite[i].first.getPosition().x > view.getCenter().x + view.getSize().x/2){
            bulletVecSprite.erase(bulletVecSprite.begin()+i);
        }
        else if(bulletVecSprite[i].first.getPosition().x < view.getCenter().x - view.getSize().x/2){
            bulletVecSprite.erase(bulletVecSprite.begin()+i);
        }
    }

// движение bullet

    for (int i = 0; i < bulletVecSprite.size(); i++){
    
        if(bulletVecSprite[i].second == 1){
            bulletVecSprite[i].first.move(0.1,0);
        }
        else if(bulletVecSprite[i].second == 0){
            bulletVecSprite[i].first.move(-0.1,0);
        }
    }
}
