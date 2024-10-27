#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

#include <iostream>

#include "objects.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Game");
    window.create(sf::VideoMode(1200,1200),"Game",sf::Style::Fullscreen);
        
    sf::Texture herotextureL; // создаём объект текстура
    herotextureL.loadFromFile("images/HeroL.png");
    sf::Texture herotextureR; // создаём объект текстура
    herotextureR.loadFromFile("images/HeroR.png");

    sf::Sprite herosprite;
    herosprite.setTexture(herotextureR);
    herosprite.setPosition(900, 735);

    herosprite.setScale(sf::Vector2f(0.125f, 0.125f)); // размер спрайта
    
    std::vector<sf::Event::KeyEvent> pressedKeys;

    bool direc_bool = false, jmp = false;
    int direc = 0; // навравление движения

    bool direcArr[2]; // проверка нажатия клавиш A/D
    float posY = herosprite.getPosition().y;

    int qwe = 0; // delete
    
    Objects obj; // текстуры
    obj.init();

    float posX [2]; // параметры для движения камерой
    posX[0] = herosprite.getPosition().x - 300;
    posX[1] = herosprite.getPosition().x + 300;

    sf::View view = window.getDefaultView();

    while (window.isOpen()){

        sf::Event event; // создаём переменную события 

        while(window.pollEvent(event)){ // пока есть события обрабатываем их
          
            if(event.type == sf::Event::Closed){ // хуй знает
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
                    direc = 1;
                }
                if(event.key.code == sf::Keyboard::D){
                    direcArr[1] = false;
                    direc = -1;
                }
            }
        }

        if(direcArr[0] && direc == -1){
            herosprite.setTexture(herotextureL);      
            herosprite.move(-0.05,0);
        }
        else if(direcArr[1] && direc == 1){
            herosprite.setTexture(herotextureR);      
            herosprite.move(0.05,0);
        }

        for(const sf::Event::KeyEvent ev : pressedKeys){ 

            switch (ev.code){
 
                case sf::Keyboard::W :
                case sf::Keyboard::Space : 
                    
                    if(jmp == false){
                        posY = herosprite.getPosition().y;
                        jmp = true;
                        direc_bool = true; // direction
                    }

                    break;

                case sf::Keyboard::C :
                if(ev.control){ // ?
                    return 0;
                }
                default:
                break;
            }  
        }

        if(jmp == true){

            if(direc_bool){
                herosprite.move(0,-0.1); // скорость прыжка
                if(posY - 200 > herosprite.getPosition().y){
                    direc_bool = false;
                }
            }
            else{
                herosprite.move(0,0.05); // скорость падения
                if(herosprite.getPosition().y > posY){
                    jmp = false;
                    direc_bool = true;
                }
            }
        }

        if(herosprite.getPosition().x < posX[0]){
            view.move(-0.05,0);
            posX[0] -= 0.05;
            posX[1] -= 0.05;
        }
        else if(herosprite.getPosition().x > posX[1]){
            view.move(0.05,0);
            posX[1] += 0.05;
            posX[0] += 0.05;
        }

        window.clear(); // clear
        
        window.setView(view);

        for(auto var : obj.draw()){
            window.draw(var);
        }
        window.draw(herosprite);
        window.display();
    }
    return 0;
}
