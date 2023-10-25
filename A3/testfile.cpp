#include <iostream>
#include <string>

#define SIZE 8

char board[SIZE][SIZE];

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
    board[SIZE/2-1][SIZE/2-1] = 'W';
    board[SIZE/2][SIZE/2] = 'W';
    board[SIZE/2-1][SIZE/2] = 'B';
    board[SIZE/2][SIZE/2-1] = 'B';
}

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool isValidMove(int row, int col, char player) {
    // check if the spot is empty
    if(board[row][col] != '-') return false;

    // example: check if this spot is a valid move for player W
    // we'll need to check all 8 directions for black neighbors

    // fill out the rest of the logic...

    // return true if it's a valid move, otherwise false
    return true;
}

int makeMove(int row, int col, char player) {
    // verify the move is valid
    if(!isValidMove(row, col, player)) return -1;

    // make the move
    board[row][col] = player;

    // flip enemy pieces in every applicable direction
    // add extra logic here...

    return 0;
}

int main() {
    initializeBoard();
    printBoard();

    // sample move
    int error = makeMove(4,5,'W');
    if(error == -1) {
        std::cout << "Invalid move!" << std::endl;
    }
    else {
        printBoard();
    }

    // Continue the game...

    return 0;
}