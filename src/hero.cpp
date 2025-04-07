#include "hero.h"

Hero::Hero(){

    heroTextureL.loadFromFile("images/HeroL.png");
    heroTextureR.loadFromFile("images/HeroR.png");

    heroSprite.setTexture(heroTextureR);
    heroSprite.setPosition(900,735);

    heroSprite.setScale(sf::Vector2f(0.125f, 0.125f)); // размер спрайта
    
    directHeroJmp = false, jmp = false;

    directHero = 1;

    posY = heroSprite.getPosition().y;

}

bool Hero::getDirect(){

    return directHero;

}

void Hero::update(std::vector<sf::Event::KeyEvent> pressedKeys){

    bool move = false; // есть ли клавиши A/D в векторе

// проверка нажатых клавиш
         
    for(auto key : pressedKeys){ 

        switch (key.code){

            case sf::Keyboard::W:
            case sf::Keyboard::Space:{
                
                if(jmp == false){ // прыжок 
                    posY = heroSprite.getPosition().y;
                    jmp = true;
                    directHeroJmp = true; // направление 
                }
                break;
            }

            case sf::Keyboard::A:{
                directHero = 0;
                move = true;
                break;
            }

            case sf::Keyboard::D:{
                directHero = 1;
                move = true;
                break;
            }

            default:
                break;
        }
    }

// проверка нажатия клавиш A/D (move) и направления движения (directHero)

    if(directHero == 0 && move){
        heroSprite.setTexture(heroTextureL);      
        heroSprite.move(-0.05,0);
    }
    else if(directHero == 1 && move){
        heroSprite.setTexture(heroTextureR);      
        heroSprite.move(0.05,0);
    }

// прыжок

    if(jmp == true){

        if(directHeroJmp){
            heroSprite.move(0,-0.1); // скорость прыжка
            if(posY - 200 > heroSprite.getPosition().y){
                directHeroJmp = false;
            }
        }
        else{
            heroSprite.move(0,0.05); // скорость падения
            if(heroSprite.getPosition().y >= posY){
                jmp = false;
                directHeroJmp = true;
            }
        }
    }
}
