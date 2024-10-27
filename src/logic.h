#include "SFML/Graphics/Sprite.hpp"
#include <SFML/Graphics.hpp>

class Logic{

    Logic();

    public:

        sf::Event event;

        bool direc_bool, jmp;
        
        int direc; // навравление движения

        bool direcArr[2]; // проверка нажатия клавиш A/D
        
        float posY;
        
        float posX [2]; // параметры для движения камерой

};
