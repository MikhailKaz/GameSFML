#include <SFML/Graphics.hpp>
#include "objects.h"
#include "logic.h"

int main()
{
    Objects obj;
    obj.init();

    Logic log;
    log.setHeroSprite(obj.getHeroSprite());
    log.setTexture(obj.getTexture());
    log.setSprite(obj.getSprite());
    
    log.mainCycle();
    
    return 0;
}
