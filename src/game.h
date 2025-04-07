#include "level_1.h"

#include "SFML/Graphics/RenderWindow.hpp"
#include <vector>

class Game{

    public:

        sf::RenderWindow window;

        sf::View view;

        std::vector<sf::Event::KeyEvent> pressedKeys;

    public:

        void run();
};


