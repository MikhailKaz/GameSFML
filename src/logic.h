#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
//#include "SFML/Window/Keyboard.hpp"

class Logic{

    public:

        sf::RenderWindow window ;

        sf::Sprite heroSprite, enemySprite, bulletSprite;
        
        sf::Texture heroTextureR, heroTextureL;

        sf::Texture enemyTextureR, enemyTextureL;

        sf::Texture bulletTextureR, bulletTextureL;
        
        bool directHeroBool, jmp;

        std::vector<sf::Event::KeyEvent> pressedKeys;

        int directHero; // навравление движения

        bool directHeroArr[2]; // проверка нажатия клавиш A/D
        
        float posY, posX [2]; // параметры для движения камерой

        sf::View view;

        std::vector <sf::Sprite> platforms;

        std::pair <bool, bool> shoot;

        std::vector <std::pair<sf::Sprite, int>> enemyVecSprite;

        std::vector <std::pair<sf::Sprite, int>> bulletVecSprite;

    public:

        Logic();

        void setStaticSprite(std::map <std::string, std::vector <sf::Sprite>>);

        void setInteractSprite(std::map <std::string, sf::Sprite>);

        void setInteractTexture(std::map <std::string,sf::Texture>);

        void mainCycle();
};


