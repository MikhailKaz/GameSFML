#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Logic{

    public:

        sf::RenderWindow window ;

        sf::Sprite heroSprite;
        sf::Texture heroTextureR, heroTextureL;

        sf::Sprite enemySprite;
        sf::Texture enemyTextureR, enemyTextureL;
        
        bool direc_bool, jmp;

        std::vector<sf::Event::KeyEvent> pressedKeys;

        int direc; // навравление движения

        bool direcArr[2]; // проверка нажатия клавиш A/D
        
        float posY, posX [2]; // параметры для движения камерой

        sf::View view;

        std::vector <sf::Sprite> platforms;

    public:

        Logic();

        void setSprite(std::vector <sf::Sprite>);

        void setCharactersSprite(std::map <std::string, sf::Sprite>);

        void setCharactersTexture(std::map <std::string,sf::Texture>);

        void mainCycle();
};


