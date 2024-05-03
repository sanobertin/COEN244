// Created by Bertin Mihigo Sano on 2023-10-14.
//

#include "Othello.h"
void clearscreen();
using std::vector;
// xPlayer represents the current player in any sutation
// yPlayer represents the other player in the same sutation


Othello::Othello(Player p1, Player p2, string boardType): othelloBoard(boardType) {
    if(p1.getDisc() == Position::BLACK) // to ensure player1 has black dics and player 2 has white dics.
        Player1 = p1;
    else if(p1.getDisc() == Position::WHITE)
        Player2 = p2;

    othelloBoard.takeTurn(Player1);

}

void Othello::play() {
    // execute function below until win / tie is reached
    while(true){

    }
}

void Othello::save() {

}
Othello::~Othello() {
    std::clog<<"Game object ends here" << std::endl;
}
// accepts row and column from user and modifies if a position is playable
void Othello::makeMove(int row, int col, Player xPlayer) { // xPlayer represents current player
    if() {
        // execute this fx only if a position is playable on the board
        if (xPlayer.pp.canPlay()) // if this function returns true
            othelloBoard.board[row][col] = xPlayer.getDisc();
        else { // execute below if player cannot play
            std::cerr << "No position available to move!\n";
            std::cout << "Do you want to: \n"
                      << "1. Forfeit your turn ?\n"
                      << "2. Concede the game? \n"
                      << "3. Save the Game?\n";
            int response;
            std::cin >> response;
            switch (response) {
                case 1:
                    //xPlayer.forfeit();
                    break;
                case 2:
                    //xPlayer.concede();
                    break;
                case 3:
                    //this->save();
                    break;
                default:
                    std::cerr << " Invalid option.\n";
                    exit(0); // end the game suddenly
            }
            clearscreen();
            othelloBoard.printBoard();

        }
    }
    else {
        std::cerr<<"Position is not empty!" << std::endl;
    }
    //end of makeMove methods
}




// implement switch colors

void Othello::flipColors(Player& arg1, Player& arg2) {
    // arg1 represents current plyer
    // arg2 represents other player
    vector<Position> pieces_to_flip;
    int row, col;

    // use deltas to find all 8 surrounding positions
    int surroundingPosDeltas[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, // 3 positions above
                                      {0, -1}, {0, 1}, // 2 positions on same row
                                      {1, -1}, {1, 0}, {1, 1}}; // 3 positions below

    // for every delta representing a neighboring position...
    for(auto deltas : surroundingPosDeltas){
        //std::cout << "deltas: [" << deltas[0] << ", " << deltas[1] << "]" << '\numberOfTokensInTheGame';

        // save what row/col currently on

        int curr_row = row + deltas[0];
        int curr_col = col + deltas[1];

        // ignore if this goes off of the board
        if(curr_row > 7 || curr_row < 0 || curr_col > 7 || curr_col < 0)
            continue;


        // save character in this position
        char char_in_pos = othelloBoard[curr_row][curr_col];

        // use this variable to save whether or not a line of pieces should be flipped
        bool flip_this_direction = false;

        // if the character in this delta position is the opponent's piece...
        if(char_in_pos == arg2.getDisc()){
            //std::cout << "Found other player at location: [" << curr_row << ", " << curr_col << "], " << char_in_pos << '\numberOfTokensInTheGame';

            // continue in this delta position until the next character is no longer the opponent's or you go off the board
            while(char_in_pos == arg2.getDisc()){
                curr_row += deltas[0];
                curr_col += deltas[1];

                // check to see if new position is off board
                if(curr_row > 7 || curr_row < 0 || curr_col > 7 || curr_col < 0)
                    break;

                // save the character
                char_in_pos = othelloBoard[curr_row][curr_col];
            }

            // if the player's piece is found after traversing over the opponent's piece(s), we know we will be flipping
            if(char_in_pos == arg2.getDisc())
                flip_this_direction = true;

            // if we found out we should be flipping...
            if(flip_this_direction){
                // save current position
                curr_row = row + deltas[0];
                curr_col = col + deltas[1];
                char_in_pos = othelloBoard[curr_row][curr_col];

                // traverse over the opponent's pieces, while saving the positions to the big list to be flipped later
                while(char_in_pos == arg2.getDisc()){
                    //std::cout << "flipping [" << curr_row << ", " << curr_col << "]\numberOfTokensInTheGame";
                    vector<int> disc = {curr_row, curr_col};
                    pieces_to_flip.push_back(disc);
                    curr_row += deltas[0];
                    curr_col += deltas[1];

                    // save next character
                    char_in_pos = othelloBoard[curr_row][curr_col];
                }

            }
        }
    }

    // after we've collecting the row/col of all discs to flipped, flip them to the current player's color/character
    for(auto pos : pieces_to_flip)
        othelloBoard[pos[0]][pos[1]] = current.setDisc();

}

void Othello::status() {
    std::cout << "\n*********************************\n";
    std::cout << "Current Player 1: " << Player1.getPlayer() << "\tpieces count: " <<Player1.getDiscsCount() << std::endl;
    std::cout << "Current Player 2: " << Player2.getPlayer() << "\tpieces count: " <<Player2.getDiscsCount() << std::endl;
    std::cout << "Current Player: " << this->current.getPlayer() <<  std::endl;
}





//***************************
// utility functions


void clearscreen(){
#ifdef _WIN32
    std::system("cls");
#elif _WIN64
    std::system("cls");
#elif __APPLE__ || __MACH__
    std::system("clear");
#endif
}
