// Created by Bertin Mihigo Sano on 2023-10-14.
//

#pragma once
#include <string>
#include <iostream>
#include "Board.h"
#include "Position.h"
using std::string;

class Player {
private:
    string name;
    char disc;
    int discsCount {0};

public:
    Player() = default;
    Player(string name);
    PlayablePosition pp;
    string getPlayer() const;
    void move();
    void concede();
    void forfeit();
    char getDisc() const;
    void setDisc(char somecharacter);
    ~Player();
};

