// Created by Bertin Mihigo Sano on 2023-10-14.
//

#pragma once
#include "Board.h"

class Position {
private:
    char piece;
public:
    Position() = default;
    virtual bool canPlay() { return false}
    static const char UNPLAYABLE = '*';
    static const char EMPTY = ' ';
    static const char BLACK = 'B';
    static const char WHITE = 'W';
};

class PlayablePosition: public Position{
private:
    char piece = Position::EMPTY;
public:
    PlayablePosition(int X, int Y); // constructor to define coordinates of a position in [8][8] board
    int coordinateX, coordinateY;
    //using Position::WHITE;
    //using Position::BLACK;
    //using Position::UNPLAYABLE;
    //using Position::EMPTY;
    bool canPlay() override;
    char getPiece();
    void setPiece(char);
};
// Position.h ends here



