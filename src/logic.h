#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <SFML/Graphics.hpp>
#include "SFML/Window/Keyboard.hpp"
#include <vector>

class Logic{

    public:

        //sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1000, 1000), "Game");
        sf::RenderWindow window ;

        sf::Sprite herosprite;

        bool direc_bool, jmp;

        std::vector<sf::Event::KeyEvent> pressedKeys;

        int direc; // навравление движения

        bool direcArr[2]; // проверка нажатия клавиш A/D
        
        float posY, posX [2]; // параметры для движения камерой

        sf::Texture herotextureR, herotextureL;

        sf::View view;

        std::vector <sf::Sprite> platforms;

    public:

        Logic();

        void setSprite(std::vector <sf::Sprite>);

        void setHeroSprite(sf::Sprite);

        void setTexture(sf::Texture *);

        void mainCycle();
};


