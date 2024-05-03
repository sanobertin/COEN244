// Created by Bertin Mihigo Sano on 2023-10-14.
//

#include "Position.h"

// check if a position is playable or not (if a player can move into this location.
/*
bool PlayablePosition::canPlay () {
    if(this->piece == UNPLAYABLE || this->piece == BLACK || this->piece == WHITE)
        return false;
    else if(this->piece == EMPTY)
        return true;
}
 */
/*
bool PlayablePosition::canPlay (Board othelloBoard, int row, int col) {
    if (othelloBoard.board[row][col] == EMPTY)
        return true;
    else if(othelloBoard.board[row][col] == EMPTY) // in all other cases it returns false.
        return false;
}
 */

bool PlayablePosition::canPlay() {
    if( piece == Position::EMPTY)
        return true;
}

char PlayablePosition::getPiece() {
    return this->piece;
}

void PlayablePosition::setPiece(char arg){
    this->piece = arg;
}