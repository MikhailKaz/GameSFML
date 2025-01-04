#include <SFML/Graphics.hpp>
#include "objects.h"
#include "logic.h"

int main()
{
    Objects obj;

    Logic log;
    log.setCharactersSprite(obj.getCharactersSprite());
    log.setCharactersTexture(obj.getCharactersTexture());
    log.setSprite(obj.getSprite());
    
    log.mainCycle();
    
    return 0;
}
