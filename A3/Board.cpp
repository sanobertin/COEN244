// Created by Bertin Mihigo Sano on 2023-10-14.
//

#include "Board.h"

void Board::drawBoard() {
    //all corner squares to be unplayable
    if(positionType == "standard"){
        for(int i = 0; i<8;i++){
            for(int j=0;j<8;j++){
                if(i == 4 && j == 3 )
                    board[i][j] = Position::WHITE;
                else if(i == 5 && j == 3 )
                    board[i][j] = Position::WHITE;
                else if(i == 4 && j == 4 )
                    board[i][j] = Position::BLACK;
                else if(i == 5 && j == 4 )
                    board[i][j] = Position::BLACK;
                else
                    board[i][j] = Position::UNPLAYABLE; // by default all position are unplayable
            }
            std::cout << std::endl;
        }
    }
    else if (positionType == "4x4"){
        for(int i = 0; i<8;i++){
            for(int j=0;j<8;j++){
                if(i == 2 && j == 2 )
                    board[i][j] = Position::WHITE;
                else if(i == 2 && j == 3 )
                    board[i][j] = Position::WHITE;
                else if(i == 4 && j == 2 )
                    board[i][j] = Position::BLACK;
                else if(i == 5 && j == 3 )
                    board[i][j] = Position::BLACK;
                else if(i == 2 && j == 4 )
                    board[i][j] = Position::WHITE;
                else if(i == 3 && j == 5 )
                    board[i][j] = Position::WHITE;
                else if(i == 4 && j == 4 )
                    board[i][j] = Position::BLACK;
                else if(i == 5 && j == 4 )
                    board[i][j] = Position::BLACK;
                else if(i== 0 && j == 0 ) // EDGES
                    board[i][j] = Position::UNPLAYABLE;
                else if(i== 7 && j == 0 ) // EDGES
                    board[i][j] = Position::UNPLAYABLE;
                else if(i== 7 && j == 7 ) // EDGES
                    board[i][j] = Position::UNPLAYABLE;
                else if(i== 7 && j == 7 ) // EDGES
                    board[i][j] = Position::UNPLAYABLE;
                else
                    board[i][j] = Position::EMPTY; // by default all position are unplayable
            }
            std::cout << std::endl;
        }
    }
    else {
        // throw an error due to invalid position type
        throw "Invalid Position Type. Should be standard or 4x4";
    }
    // end of drawBoard
}
// A simple method to print current board
void Board::printBoard() {
    for(int i = 0; i<8;i++) { //ROW
        for (int j = 0; j < 8; j++) { // COLUMN
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}


























