// Created by Bertin Mihigo Sano on 2023-10-14.
//

#pragma once
#include<string>
#include <iostream>
#include "Player.h"
#include "Position.h"
using std::string;

class Board {
private:
    string positionType; // standard or 4x4
public:
    Board() = default;
    char board[8][8];
    void drawBoard();
    void printBoard();
    Board(string positions);
    ~Board();
    //void takeTurn(Player current);
};


