#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Enemy{

    public:

        sf::Texture enemyTextureL;
        sf::Texture enemyTextureR;

        sf::Sprite enemySprite;

        std::vector <std::pair<sf::Sprite, bool>> enemyVecSprite;

    public:

        Enemy();

        void update(sf::View, sf::Sprite heroSprite);

};
