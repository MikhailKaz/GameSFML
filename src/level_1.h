#include "SFML/Window/Window.hpp"
#include "hero.h"
#include "enemy.h"
#include "bullet.h"

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Level_1{

    public:

        sf::Texture platformTexture_1, platformTexture_2;
        sf::Sprite platformSprite_1, platformSprite_2;

        std::vector <sf::Sprite> platforms;

        float posX[2]; // для движения окна

        Hero hero;

        Enemy enemy;

        Bullet bullet;

    public:

        Level_1();

        void update(sf::View& view, std::vector<sf::Event::KeyEvent> pressedKeys);

        void draw(sf::RenderWindow& window);

        std::vector <sf::Sprite> getVecSprite(); // платформы
};
