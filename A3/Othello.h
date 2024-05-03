// Created by Bertin Mihigo Sano on 2023-10-14.
//

// This Class represents the Game Class
#pragma once
#include "Player.h"
#include "Board.h"
#include "Position.h"
#include <stdlib.h>
#include <string>
using std::string;

class Othello final{
private:
    Player Player1;
    Player Player2;
    Player current; // to track current player
    void flipColors(Player& arg1, Player& arg2); // first arg implies current player
public:
    Othello(Player,Player,string);
    ~Othello();
    Board othelloBoard;
    void start();
    Board load();
    void play();
    void makeMove(int row, int col, Player xPlayer);
    void save();
    void status();

};

