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
    Player xPlayer; // this instance denotes a player who can make changes to the Board
public:
    Board(string);
    char board[8][8];
    void drawBoard();
    void printBoard();
    void takeTurn(Player& xPlayer); // this function is used to switch players who can modify on board
    //~Board();
    //void takeTurn(Player current);
};


