#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>


using namespace std;

class TicTacToe{
private:
    const char X = 'X', O = 'O', SPACE = '.';
    char board[9];
    char currentPlayer;
    bool won = false, moreMoves = true;
public:
    TicTacToe(char currentPlayer='X'){
        this->currentPlayer = currentPlayer;
        // initialize
        for(int i = 0; i < 9; i++) board[i] = SPACE;
    }


    void printBoard(char* board) {
        for(int y = 0; y < 3; y++) { // A line
            cout << "\t";
            for(int x = 0; x < 3; x++) { // An entry
                cout << board[x+y*3];
            }
            cout << endl;
        }
    }
    void Play(){
        //Do many turns
        do {
        //Draw the board
        printBoard(board);
        cout << "Please place an " << currentPlayer << " by choosing 0 to 8." << endl;

        //Get a play
        int play;
        cin >> play;

        //Confirm the play is on the board
        if(play < 0 || play >8) {
            cout << "Invalid range, please pick a position between 0 and 8, inclusive." << endl;
            continue;
        }

        if(board[play] != SPACE) {
            cout << "Position " << play << " is already occupied!" << endl;
            continue;
        }
        board[play] = currentPlayer;

        for(int y = 0; y < 3; y++) { // Checking Rows
            won |= (board[0 + y*3] != SPACE) && (board[0 + y*3] == board[1 + y*3]) && (board[1 + y*3] == board[2 + y*3]);
        }
        for(int x = 0; x < 3; x++) { // Checking Columns
            won |= (board[x + 0*3] != SPACE) && (board[x + 0*3] == board[x + 1*3]) && (board[x + 1*3] == board[x + 2*3]);
        }
        won |= (board[4] != SPACE) && (board[0] == board[4]) && (board[4] == board[8]);
        won |= (board[4] != SPACE) && (board[6] == board[4]) && (board[4] == board[2]);

        moreMoves = false;
        for(int i = 0; i < 9; i++) {
            moreMoves |= (board[i] == SPACE);
        }

        if(currentPlayer == X) currentPlayer = O;
        else currentPlayer = X;
    } while (!won && moreMoves);
    }

    ~TicTacToe() {
        //Draw the final board
        printBoard(board);
        //Declare winner, if someone won
        if(won) {
            if(currentPlayer == X) cout << O << " won!" << endl;
            else cout << X << " won!" << endl;
        } // Declare Tie if nobody won
        else if (!moreMoves) cout << "Tie Game!" << endl;

        getchar();
}

};



int main() {
    //Set up board like this:
    //{.,.,.,
    // .,.,.,
    // .,.,.}

    //00 01 02
    //03 04 05
    //06 07 08
    TicTacToe TTT;
    TTT.Play();

    return 0;
}
