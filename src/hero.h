#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Hero{

    public:

        sf::Texture heroTextureL;
        sf::Texture heroTextureR;

        sf::Sprite heroSprite;

        bool directHeroJmp, jmp; // проверка прыжка и его направления (up/down)

        bool directHero; // направление движения

        float posY; // значение куда должнен вернуться hero при прыжке

    public:
        
        Hero();

        std::pair <bool, bool>& getShoot();

        bool getDirect();

        void update(std::vector<sf::Event::KeyEvent> pressedKeys);

};
