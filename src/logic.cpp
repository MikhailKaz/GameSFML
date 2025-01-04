#include "logic.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

Logic::Logic(){

    direc_bool = false, jmp = false;

    direc = 0;

    posY = heroSprite.getPosition().y;

}

void Logic::setCharactersSprite(std::map <std::string, sf::Sprite> dictCharactersSprite){

    heroSprite = dictCharactersSprite ["heroSprite"];
    enemySprite = dictCharactersSprite ["enemySprite"];

}

void Logic::setCharactersTexture(std::map <std::string,sf::Texture> dictCharactersTexture){

    heroTextureL = dictCharactersTexture["heroTextureL"];
    heroTextureR = dictCharactersTexture["heroTextureR"];

    enemyTextureL = dictCharactersTexture["enemyTextureL"];
    enemyTextureR = dictCharactersTexture["enemyTextureR"];

}

void Logic::setSprite(std::vector <sf::Sprite> platform_s){
    platforms = platform_s;
}

void Logic::mainCycle(){

    window.create(sf::VideoMode(1200,1200),"Game",sf::Style::Fullscreen);
    view = window.getDefaultView();
 
    posX[0] = heroSprite.getPosition().x - 300;
    posX[1] = heroSprite.getPosition().x + 300;

    while (window.isOpen()){

            sf::Event event; // создаём переменную события 

            while(window.pollEvent(event)){ // пока есть события обрабатываем их
              
                if(event.type == sf::Event::Closed){ // событие закрытия окна
                    window.close();
                }

                if(event.type == sf::Event::KeyPressed){ // true если клавиша нажата, если такая клавиша уже есть в векторе то falsebool
                    bool isNew = true;
                for(const sf::Event::KeyEvent ev : pressedKeys){ 
                    if(ev.code == event.key.code){  
                      isNew = false;
                      break;
                    }
                }
                if(event.key.code == sf::Keyboard::A){
                    direcArr[0] = true;
                    direc = -1;
                }
                else if(event.key.code == sf::Keyboard::D){
                    direcArr[1] = true;
                    direc = 1;
                }

                if(isNew){
                    pressedKeys.push_back(event.key);
                  }
                }

                else if(event.type == sf::Event::KeyReleased){ // иначе если клавиша отжата удаляем её из вектора
                    for(auto it = pressedKeys.begin(); it != pressedKeys.end(); it++){
                        if(it->code == event.key.code){
                            pressedKeys.erase(it); 
                            break;
                        }
                    }
                    if(event.key.code == sf::Keyboard::A){
                        direcArr[0] = false;
                        if(direcArr[1] == true){
                            direc = 1;
                        }
                        
                    }
                    if(event.key.code == sf::Keyboard::D){
                        direcArr[1] = false;
                        if(direcArr[0] == true){
                            direc = -1;
                        }
                    }
                }
            }

// проверка нажатия клавиш A/D (direcArr) и направления движения (direc)

            if(direcArr[0] && direc == -1){
                heroSprite.setTexture(heroTextureL);      
                heroSprite.move(-0.05,0);
            }
            else if(direcArr[1] && direc == 1){
                heroSprite.setTexture(heroTextureR);      
                heroSprite.move(0.05,0);
            }

// прыжок
         
            for(const sf::Event::KeyEvent ev : pressedKeys){ 

                switch (ev.code){
     
                    case sf::Keyboard::W :
                    case sf::Keyboard::Space : 
                        
                        if(jmp == false){
                            posY = heroSprite.getPosition().y;
                            jmp = true;
                            direc_bool = true; // direction
                        }

                        break;

                    case sf::Keyboard::Escape:
                        return;

                    default:
                        break;
                }  
            }
        
            if(jmp == true){

                if(direc_bool){
                    heroSprite.move(0,-0.1); // скорость прыжка
                    if(posY - 200 > heroSprite.getPosition().y){
                        direc_bool = false;
                    }
                }
                else{
                    heroSprite.move(0,0.05); // скорость падения
                    if(heroSprite.getPosition().y > posY){
                        jmp = false;
                        direc_bool = true;
                    }
                }
            }

// движеие окна
            
            if(heroSprite.getPosition().x < posX[0]){
                view.move(-0.05,0);
                posX[0] -= 0.05;
                posX[1] -= 0.05;
            }
            else if(heroSprite.getPosition().x > posX[1]){
                view.move(0.05,0);
                posX[1] += 0.05;
                posX[0] += 0.05;
            }

// движение enemy

            if(enemySprite.getPosition().x < 2000){
                enemySprite.move(0.05,0);
            }
            else{
                enemySprite.setPosition(0,735);
            }
            if(enemySprite.getPosition().x + 30 > heroSprite.getPosition().x && 
                    enemySprite.getPosition().x - 30 < heroSprite.getPosition().x){

                if(enemySprite.getPosition().y - 30 < heroSprite.getPosition().y + 30){
                    return;
                } 
            }
            else if(enemySprite.getPosition().x > heroSprite.getPosition().x){
            }

// отрисовка

            window.clear();
            
            window.setView(view);

            for(auto var : platforms){
                window.draw(var);
            }

            window.draw(enemySprite);
            window.draw(heroSprite);
            window.display();
    }
}
