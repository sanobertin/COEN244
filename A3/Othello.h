// Created by Bertin Mihigo Sano on 2023-10-14.
//

// This Class represents the Game Class
#pragma once
#include "Player.h"
#include "Board.h"
#include "Position.h"
#include <stdlib.h>


class Othello{
private:
    Player Player1;
    Player Player2;
    Player current; // to track current player
    Board gameBoard;
    void save();
public:
    Othello(Player p1, Player p2);
    ~Othello();
    void start();
    Board load();
    void play();
    void makeMove(int row, int col, Player p);

};


void clearscreen(){
#ifdef _WIN32
    std::system("cls");
#elif _WIN64
    std::system("cls");
#elif __APPLE__ || __MACH__
    std::system("clear");
#endif
}
