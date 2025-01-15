#include "logic.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Window/Keyboard.hpp"

//delete
#include <iostream>
#include <utility>
//

Logic::Logic(){

    directHeroBool = false, jmp = false;

    directHero = 0;

    posY = heroSprite.getPosition().y;

    shoot.first = false;
    shoot.second = true;

}

void Logic::setInteractSprite(std::map <std::string, sf::Sprite> dictInteractsSprite){

    heroSprite = dictInteractsSprite ["heroSprite"];

// delete ?

    // enemySprite = dictInteractsSprite ["enemySprite"]; // не используется 

    // bulletSprite = dictInteractsSprite ["bulletSprite"]; // не используется 
//

}

void Logic::setInteractTexture(std::map <std::string,sf::Texture> dictInteractsTexture){

    heroTextureL = dictInteractsTexture["heroTextureL"];
    heroTextureR = dictInteractsTexture["heroTextureR"];

    enemyTextureL = dictInteractsTexture["enemyTextureL"];
    enemyTextureR = dictInteractsTexture["enemyTextureR"];

    bulletTextureL = dictInteractsTexture["bulletTextureL"];
    bulletTextureR = dictInteractsTexture["bulletTextureR"];

}

void Logic::setStaticSprite(std::map <std::string, std::vector <sf::Sprite>> dictStaticSprite){
    platforms = dictStaticSprite["platforms"];
}

void Logic::mainCycle(){

    window.create(sf::VideoMode(1200,1200),"Game",sf::Style::Fullscreen);
    view = window.getDefaultView();
 
    posX[0] = heroSprite.getPosition().x - 300;
    posX[1] = heroSprite.getPosition().x + 300;

    srand(time(0));

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
                    directHeroArr[0] = true;
                    directHero = -1;
                }
                else if(event.key.code == sf::Keyboard::D){
                    directHeroArr[1] = true;
                    directHero = 1;
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
                        directHeroArr[0] = false;
                        if(directHeroArr[1] == true){
                            directHero = 1;
                        }
                        
                    }

                    if(event.key.code == sf::Keyboard::D){
                        directHeroArr[1] = false;
                        if(directHeroArr[0] == true){
                            directHero = -1;
                        }
                    }

                    if(event.key.code == sf::Keyboard::Enter){
                        shoot.second = true;
                        shoot.first = false;
                    }
                }
            }

// проверка нажатия клавиш A/D (directHeroArr) и направления движения (directHero)

            if(directHeroArr[0] && directHero == -1){
                heroSprite.setTexture(heroTextureL);      
                heroSprite.move(-0.05,0);
            }
            else if(directHeroArr[1] && directHero == 1){
                heroSprite.setTexture(heroTextureR);      
                heroSprite.move(0.05,0);
            }

// проверка нажатых клавиш
         
            for(const sf::Event::KeyEvent ev : pressedKeys){ 

                switch (ev.code){
     
                    case sf::Keyboard::W:
                    case sf::Keyboard::Space: 
                        
                        if(jmp == false){ // прыжок 
                            posY = heroSprite.getPosition().y;
                            jmp = true;
                            directHeroBool = true; // направление 
                        }

                        break;

                    case sf::Keyboard::Enter:{

                        shoot.first = true;
                        break;
                    }

                    case sf::Keyboard::Escape:
                        return;

                    default:
                        break;
                }  
            }

// прыжок
            if(jmp == true){

                if(directHeroBool){
                    heroSprite.move(0,-0.1); // скорость прыжка
                    if(posY - 200 > heroSprite.getPosition().y){
                        directHeroBool = false;
                    }
                }
                else{
                    heroSprite.move(0,0.05); // скорость падения
                    if(heroSprite.getPosition().y >= posY){
                        jmp = false;
                        directHeroBool = true;
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

// добавление enemy

            if(enemyVecSprite.size() < 3){ // 3 enemy пока так

                for(int i = 0, random, direct; enemyVecSprite.size() < 3; i++){

                    sf::Sprite enemySprite;

                    enemySprite.setScale(sf::Vector2f(0.5f, 0.5f));

                    do{
                        random = rand() % int(view.getCenter().x + view.getSize().x / 2) + view.getCenter().x - view.getSize().x / 2; // rand % b + a
                    }
                    while(random > (heroSprite.getPosition().x - 400) && random < heroSprite.getPosition().x + 400);

                    if(random < heroSprite.getPosition().x){
                        direct = 1;
                        enemySprite.setTexture(enemyTextureR);
                    }
                    else if(random > heroSprite.getPosition().x){
                        direct = -1;
                        enemySprite.setTexture(enemyTextureL);
                    }

                    enemySprite.setPosition(random, 735);
                    enemyVecSprite.push_back(std::make_pair(enemySprite, direct));
                }
            }

// движение enemy

            for(int i = 0; i < enemyVecSprite.size(); i++){
                if(enemyVecSprite[i].first.getPosition().x < heroSprite.getPosition().x){
                    enemyVecSprite[i].first.move(0.05,0);
                    enemyVecSprite[i].first.setTexture(enemyTextureR);
                }
                else if(enemyVecSprite[i].first.getPosition().x > heroSprite.getPosition().x){
                    enemyVecSprite[i].first.move(-0.05,0);
                    enemyVecSprite[i].first.setTexture(enemyTextureL);
                }
            }

// добавление bullet

            if(shoot.first && shoot.second){ // новое нажатие Enter

                sf::Sprite bulletSprite;

                std::pair <sf::Sprite, int> bullet;

                if(directHero == 1 || directHero == 0){

                    bulletSprite.setPosition(heroSprite.getPosition().x + 60,heroSprite.getPosition().y + 32);
                    bulletSprite.setTexture(bulletTextureR);
                }

                else if(directHero == -1){
                    bulletSprite.setPosition(heroSprite.getPosition().x,heroSprite.getPosition().y + 32);
                    bulletSprite.setTexture(bulletTextureL);
                }

                bullet.first = bulletSprite;

                if(directHero != 0){
                    bullet.second = directHero;
                }
                else{
                    bullet.second = 1;
                }
                
                bulletVecSprite.push_back(bullet); // X/Y/направление
                
                shoot.second = false; // обновится в проверке отжатия клавиш                                                
            } 

// движение bullet

            for (int i = 0; i < bulletVecSprite.size(); i++){
            
                if(bulletVecSprite[i].second == 1 || bulletVecSprite[i].second == 0){
                    bulletVecSprite[i].first.move(0.1,0);
                }
                else if(bulletVecSprite[i].second == -1){
                    bulletVecSprite[i].first.move(-0.1,0);
                }
            }

// проверка полёта bullet, удаление объектов (enemy,bullet)

            for(int sort = 0, count = 0; sort == 0;){ // пузырёк (enemyVecSprite)

                for(int i = 0; i < enemyVecSprite.size() - 1; i++){

                    if(enemyVecSprite[i].first.getPosition().x > enemyVecSprite[i+1].first.getPosition().x){
                        
                        count++;

                        auto enemyMax = enemyVecSprite[i].first; 
                       
                        enemyVecSprite[i].first.setPosition(enemyVecSprite[i+1].first.getPosition().x, enemyVecSprite[i+1].first.getPosition().y);
                        enemyVecSprite[i+1].first.setPosition(enemyMax.getPosition().x, enemyMax.getPosition().y);
                    }
                }

                if(count == 0){
                    sort = 1;
                }
                else{
                    sort = 0;
                    count = 0;
                }
            }

            for(int j = 0; j < bulletVecSprite.size(); j++){

                if(bulletVecSprite[j].second == 1){

                    for(int i = 0; i < enemyVecSprite.size(); i++){
                        
                        if(enemyVecSprite[i].first.getPosition().x + 60 >= bulletVecSprite[j].first.getPosition().x 
                                && enemyVecSprite[i].first.getPosition().x <= bulletVecSprite[j].first.getPosition().x){

                            if(enemyVecSprite[i].first.getPosition().y + 60 >= bulletVecSprite[j].first.getPosition().y 
                                    && enemyVecSprite[i].first.getPosition().y <= bulletVecSprite[j].first.getPosition().y){

                                enemyVecSprite.erase(enemyVecSprite.begin()+i);
                                bulletVecSprite.erase(bulletVecSprite.begin()+j);

                            }
                        }
                    }
                }

                else if(bulletVecSprite[j].second == -1){

                    for(int i = enemyVecSprite.size() - 1; i >= 0; i--){
                        
                        if(enemyVecSprite[i].first.getPosition().x + 60 >= bulletVecSprite[j].first.getPosition().x 
                                && enemyVecSprite[i].first.getPosition().x <= bulletVecSprite[j].first.getPosition().x){

                            if(enemyVecSprite[i].first.getPosition().y + 60 >= bulletVecSprite[j].first.getPosition().y 
                                    && enemyVecSprite[i].first.getPosition().y <= bulletVecSprite[j].first.getPosition().y){

                                enemyVecSprite.erase(enemyVecSprite.begin()+i);
                                bulletVecSprite.erase(bulletVecSprite.begin()+j);

                            }
                        }
                    }
                }
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

// проверка на game over

            for (auto enemySprite : enemyVecSprite){ // 70/60/50 хитбоксы
                
                if(enemySprite.first.getPosition().x + 70 >= heroSprite.getPosition().x && 
                        enemySprite.first.getPosition().x <= heroSprite.getPosition().x){

                    if(enemySprite.first.getPosition().y <= heroSprite.getPosition().y &&
                            enemySprite.first.getPosition().y + 60 >= heroSprite.getPosition().y){
                        return;
                    }

                    else if(enemySprite.first.getPosition().y <= heroSprite.getPosition().y + 60 &&
                            enemySprite.first.getPosition().y + 60 >= heroSprite.getPosition().y + 60){
                        return;
                    }
                }
                
                else if(enemySprite.first.getPosition().x + 70 >= heroSprite.getPosition().x + 50 && 
                        enemySprite.first.getPosition().x <= heroSprite.getPosition().x + 50){
                    
                    if(enemySprite.first.getPosition().y <= heroSprite.getPosition().y &&
                            enemySprite.first.getPosition().y + 60 >= heroSprite.getPosition().y){
                        return;
                    }

                    else if(enemySprite.first.getPosition().y <= heroSprite.getPosition().y + 60 &&
                            enemySprite.first.getPosition().y + 60 >= heroSprite.getPosition().y + 60){
                        return;
                    }
               }
            }
            
// отрисовка

            window.clear();

            window.setView(view);

            for(auto bullet : bulletVecSprite){
                window.draw(bullet.first);
            }

            for(auto platform : platforms){
                window.draw(platform);
            }

            for(auto var : enemyVecSprite){
                window.draw(var.first);
            }

            window.draw(heroSprite);
            window.display();
    }
}

// размеры моделек : 60x60
