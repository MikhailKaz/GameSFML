#include <SFML/Graphics.hpp>
#include "objects.h"
#include "logic.h"

int main()
{
    Objects obj;

    Logic log;
    log.setInteractSprite(obj.getInteractSprite());
    log.setInteractTexture(obj.getInteractTexture());
    log.setStaticSprite(obj.getStaticSprite());
    
    log.mainCycle();
    
    return 0;
}
