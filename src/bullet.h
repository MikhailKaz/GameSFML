#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Bullet{

    public:

        sf::Texture bulletTextureL;
        sf::Texture bulletTextureR;

        sf::Sprite bulletSprite;

        std::pair <bool, bool> shoot; // Условие добавление пули

        std::vector <std::pair<sf::Sprite, bool>> bulletVecSprite;

    public:

        Bullet();

        void update(sf::View, std::vector<sf::Event::KeyEvent> pressedKeys, bool directHero, sf::Sprite heroSprite);

};
