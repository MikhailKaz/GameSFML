#include "logic.h"

Logic::Logic(){

    direc_bool = false, jmp = false;

    direc = 0;

    posY = herosprite.getPosition().y;
 
    posX[0] = herosprite.getPosition().x - 300;
    posX[1] = herosprite.getPosition().x + 300;

}

