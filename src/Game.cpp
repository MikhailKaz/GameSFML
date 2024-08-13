#include <SFML/Graphics.hpp>
#include <vector>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Game");
    window.create(sf::VideoMode(1000,1000),"Game",sf::Style::Fullscreen);
        
    sf::Texture herotextureL; // создаём объект текстура
    herotextureL.loadFromFile("images/HeroL.png");
    
    sf::Texture herotextureR; // создаём объект текстура
    herotextureR.loadFromFile("images/HeroR.png");

    sf::Sprite herosprite;
    herosprite.setTexture(herotextureR);
    herosprite.setPosition(310,200);

    herosprite.setScale(sf::Vector2f(0.075f, 0.075f)); // размер спрайта
    
    // sf::Vector2f pos;
    // herosprite.setPosition(pos.x,pos.y);

    std::vector<sf::Event::KeyEvent> pressedKeys;

    while (window.isOpen()){

        sf::Event event; // создаём переменную события 
        while(window.pollEvent(event)){ // пока есть события обрабатываем их
          
            if(event.type == sf::Event::Closed){
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
        
        for(const sf::Event::KeyEvent ev : pressedKeys){ 
            switch (ev.code){
                case sf::Keyboard::Left : 
                    
                    herosprite.setTexture(herotextureL);
                    herosprite.move(-0.1,0);
                    break;
                
                case sf::Keyboard::Right : 
            
                    herosprite.setTexture(herotextureR);
                    herosprite.move(0.1,0);
                    break;
        
                case sf::Keyboard::Up : 
            
                herosprite.move(0,-0.1);
                break;

                case sf::Keyboard::Down : 
            
                herosprite.move(0,0.1);
                break;

                case sf::Keyboard::C :
                if(ev.control){
                    return 0;
                }
                default:
                break;
            }  
        }
        window.clear();
        window.draw(herosprite);
        window.display();
    }
    return 0;
}
