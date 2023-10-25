// Created by Bertin Mihigo Sano on 2023-10-14.
//

#pragma once


class Position {
private:
    char piece;
public:
    Position();
    ~Position();
    virtual bool canPlay() = 0;
    static const char UNPLAYABLE = '*';
    static const char EMPTY = ' ';
    static const char BLACK = 'B';
    static const char WHITE = 'W';
};

class PlayablePosition: public Position{
private:
    char piece;
public:
    bool canPlay() override;
    friend class Board;
};


