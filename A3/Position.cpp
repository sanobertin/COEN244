// Created by Bertin Mihigo Sano on 2023-10-14.
//

#include "Position.h"


// check if a position is playable or not (if a player can move into this location.
bool PlayablePosition::canPlay () {
    if(this->piece == UNPLAYABLE || this->piece == BLACK || this->piece == WHITE)
    return false;
    else if(this->piece == EMPTY)
        return true;
}
