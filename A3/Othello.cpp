// Created by Bertin Mihigo Sano on 2023-10-14.
//

#include "Othello.h"


Othello::Othello(Player p1, Player p2, string boardtype) {
    Player1 = p1;
    Player2 = p2;
    gameBoard = Board(boardtype);
}


void Othello::play() {
    // execute function below until win / tie is reached
    while(true){

    }
}

void Othello::save() {

}
Othello::~Othello() {
    // print board state current
    // print who won
}
// accepts row and column from user and modifies if a position is playable
void Othello::makeMove(int row, int col, Player p) {
    if(p.pp.canPlay()) // if this function returns true
        gameBoard.board[row][col] = p.getDisc();
    else { // execute below if player cannot play
        std::cerr << "No position available to move!\n";
        std:: cout << "Do you want to: \n"
                    << "1. Forfeit your turn ?\n"
                    << "2. Concede the game? \n"
                    << "3. Save the Game?\n";
        int response;
        std::cin >> response;
        switch (response) {
            case 1:
                p.forfeit();
                break;
            case 2:
                p.concede();
                break;
            case 3:
                this->save();
                break;
            default:
                std::cerr << " Invalid option.\n";
                exit(0); // end the game suddenly
        }
        clearscreen();
        gameBoard.printBoard();

    }

}
