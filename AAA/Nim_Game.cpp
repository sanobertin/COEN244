#include "Nim.h"

//Not sure how well it works. I tried making it fail a few times by putting in the wrong values and so far so good. LMK if you run into any problems.
// Also, sorry for the mess of functions haha. I tried to label them. I don't really know how I would clean it up. If you have any ideas please go for it.

using namespace std;


int main() {
    Nim game();

    cout << "Welcome to the Nim game!\n";
    players();
    switch (numOfPlayers){
        case 1:
            cout << "\nPlease enter a name: ";
            cin >> player1; cout << endl;
            break;
        case 2:
            cout << "\nPlease enter a name for player 1: ";
            cin >> player1;
            cout << "\nPlease enter a name for player 2: ";
            cin >> player2; cout << endl;
            break;
        default:
            cout << "\nInvalid entry. Please try again.";
            players();
            break;
    }
    if (numOfPlayers == 2){          //If statement to start the 2 player game, the else will start the 1 player mode instead.
        numOfTokens();
        int count = n;               // the next 2 lines are variables used to make sure the winner is announced on the last token.
        int check = n;

        pileShuffle(A, a);
        pileShuffle(B, b);
        pileShuffle(C, c);
        pileShuffle(D, d);
        for (int i = 0; i < n; i++){ E[i] = 'O';}// this just takes the rest of the tokens and assigns them to the last heap


        twoPlayerNim(count, check);
    }






    return 0;

}
