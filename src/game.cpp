#include "game.h"

void Game::run(){

    window.create(sf::VideoMode(1200,1200),"Game",sf::Style::Fullscreen);
    view = window.getDefaultView();

    Level_1 level_1;
 
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
            }
        }

// Выход по ESC

        for (const sf::Event::KeyEvent key : pressedKeys){

            if(key.code == sf::Keyboard::Escape){
                exit(0);
            }
        }

        level_1.update(view, pressedKeys);

// отрисовка

        window.clear();

        window.setView(view);

        level_1.draw(window);

        window.display();
    }
}
// размеры моделек : 60x60
