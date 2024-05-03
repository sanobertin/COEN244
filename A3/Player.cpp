// Created by Bertin Mihigo Sano on 2023-10-14.
//

#include "Player.h"
#include "Board.h"

Player::Player(std::string name) {
    this->name = name;
}

string Player::getPlayer() const {
    return this->name;
}

char Player::getDisc() const {
    return this->disc;
}

void Player::setDisc(char somecharacter) {
    this->disc =  somecharacter;
}

int Player::getDiscsCount() const {
    return this->discsCount;
}

void Player::discsIncrement(){
    discsCount++;
}

void Player::discsDecrement(){
    discsCount--;
}
Player::~Player() {
    std::clog << "\nDestroying Player "<<name<<std::endl;
}
