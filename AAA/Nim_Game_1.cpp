#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
using namespace std;
// global variables
int numberOfTokensInTheGame{};
int copy_token {numberOfTokensInTheGame}; // copy just
char A[20], B[20], C[20], D[20], E[20];
//int numberOfTokensInTheGame{0};
int numOfPlayers{0};
//int tokens{0}; // this var being global causes issues!
int a, b, c, d;
int turn{}; // this will be used to switch turns between players 0 and 1.
char heap;
string player1, player2;
// end of global variables

// function prototypes
void heapUpdate(char heapToUpdate[], int tokens_to_remove);
void twoPlayerNim(int& number_of_tokens_in_the_game); // pass this by reference as it will update the number of tokens in the game
void PLAYERvsCPU(int& number_of_tokens_in_the_game);
void menu();
void checkWinner(const int& number_of_tokens_in_game, int whose_turn); // arg1 is the number of tokens in the game, arg2 is whose turn it is (0 or 1)
void pileShuffle(char pile[], int RANDOM);
void showHeaps(char A[], char B[], char C[], char D[], char E[]); // displays the heaps
bool heapCheck(char Heap[]);
int generate_random_number_btn_one_to_tokens();

// end of function prototypes

//Not sure how well it works. I tried making it fail a few times by putting in the wrong values and so far so good. LMK if you run into any problems.
// Also, sorry for the mess of functions haha. I tried to label them. I don't really know how I would clean it up. If you have any ideas please go for it.





















int main(){
    cout << "Welcome to the Nim game!\n";
    menu(); // this function will display the menu and ask the user to choose an option
    return 0;

}

int generate_random_number_btn_one_to_tokens(){     //Random number generator for the 2 player game heaps
        random_device generator;
        uniform_int_distribution<int> distro(1, numberOfTokensInTheGame / 2);
        return distro(generator);
    }



void checkWinner(const int& number_of_tokens_in_game, int whose_turn){
    if(number_of_tokens_in_game==0){
        if(whose_turn==0){
            cout << player1 << " wins!" << endl;
        }
        else if(whose_turn==1){
            cout << player2 << " wins!" << endl;
        }
        menu(); // return to game menu
    }
}



void pileShuffle(char pile[], int RANDOM){// assigns a random number to an int variable and uses that variable to assign
    RANDOM = generate_random_number_btn_one_to_tokens();                       // that amount of tokens to a certain heap array
    for (int i = 0; i < RANDOM; i++){
        pile[i] = 'O';
    }

    copy_token = copy_token -RANDOM;
}


void showHeaps(char A[], char B[], char C[], char D[], char E[]){ // displays the heaps
    cout << endl << "A:  ";
    for (int i = 0; i < 20; i++){
        if(A[i] != 'O') {cout << " "; continue;}
        cout << A[i];
    }
    cout << endl << "B:  ";
    for (int i = 0; i < 20; i++){
        if(B[i] != 'O') {cout << " "; continue;}
        cout << B[i];
    }
    cout << endl << "C:  ";
    for (int i = 0; i < 20; i++){
        if(C[i] != 'O') {cout << " "; continue;}
        cout << C[i];
    }
    cout << endl << "D:  ";
    for (int i = 0; i < 20; i++){
        if(D[i] != 'O') {cout << " "; continue;}
        cout << D[i];
    }
    cout << endl << "E:  ";
    for (int i = 0; i < 20; i++){
        if(E[i] != 'O') {cout << " "; continue;}
        cout << E[i];
    }
}


bool heapCheck(char Heap[]){ // this function checks if there are enough tokens left in the chosen heap
    int length = 20; // get the size of the heap
    int howManyTokensRemainingOnAHeap = 0;
    for (int i = 0; i < length; i++){
        if (Heap[i] == 'O'){ // if there is a token in the heap, return true
            howManyTokensRemainingOnAHeap++;
        }
        else { continue;}
    }
    if(howManyTokensRemainingOnAHeap !=0)
        return true;
    else
        return false;
}


void heapUpdate(char heapToUpdate[], int tokens_to_remove) { // ideally must passby reference char array by reference as it will update the heap!
    int length = 20;
    //int length = sizeof(heapToUpdate)/sizeof(char); // get the size of the heap
    int howManyTokensRemainingOnAHeap = 0;
    for (int i = 0; i < length; i++){
        if (heapToUpdate[i] == 'O'){ // if there is a token in the heap, return true
            howManyTokensRemainingOnAHeap++;
        }
        else { continue;}
    }
    if (howManyTokensRemainingOnAHeap < tokens_to_remove) { // if there are not enough tokens left in the heap, return void
        cout << "There are not enough tokens left in this pile." << endl;
        return;
    }
    else {
        for (int i = 0; i < length; i++) {
            if (heapToUpdate[i] == 'O' && tokens_to_remove > 0) {
                heapToUpdate[i] = ' ';
                tokens_to_remove--;
            }
        }
    }
//tokens = 0 ; // reset the tokens to 0
//end of function here
}





    void menu(){
        cout << "1. Player vs CPU\n"
                "2. 2 players\n"
                "3. Exit\n";
        int choice;
        while(true) {
            cin >> choice;
            if (choice < 1 || choice > 3) {
                cerr << "Invalid entry. Please try again.\n";cerr.flush();
                cin.ignore();
                cin.clear();
            }
            else break;
        }
        switch (choice){
            case 1:
                cout << "Player vs CPU" << endl;
                cout << "Enter Player 1 name: ";
                cin >> player1;
                player2 = "CPU";
                cout << player1 << " vs " << player2 << endl;
                cout << "\nPlease enter an integer between 10 and 20 for the number of tokens you would like to have in the game: ";
                while(true) { // this loops until the user enters a valid input
                    cin >> numberOfTokensInTheGame;
                    if (numberOfTokensInTheGame < 10 || numberOfTokensInTheGame > 20) {
                        cerr << "\nEnsure the number of tokes is between 10 and 20.\n"; cerr.flush();
                        cin.clear(); // this line ignore unwanted input specified above
                    }
                    else break;
                }
                copy_token = numberOfTokensInTheGame;

                pileShuffle(A, a);
                pileShuffle(B, b);
                pileShuffle(C, c);
                pileShuffle(D, d);
                for (int i = 0; i < copy_token; i++){ E[i] = 'O';}
                PLAYERvsCPU(numberOfTokensInTheGame);
                break;
            case 2:
                cout << "2 Players" << endl;
                cout << "Enter Player 1 name: ";
                cin >> player1;
                cout << "Enter Player 2 name: ";
                cin >> player2;
                cout << player1 << " vs " << player2 << endl;
                cout << "\nPlease enter an integer between 10 and 20 for the number of tokens you would like to have in the game: ";
                while(true) { // this loops until the user enters a valid input
                    cin >> numberOfTokensInTheGame;
                    if (numberOfTokensInTheGame < 10 || numberOfTokensInTheGame > 20) {
                        cerr << "\nEnsure the number of tokes is between 10 and 20.\n"; cerr.flush();
                        cin.clear(); // this line ignore unwanted input specified above
                    }
                    else break;
                }
                copy_token = numberOfTokensInTheGame;

                pileShuffle(A, a);
                pileShuffle(B, b);
                pileShuffle(C, c);
                pileShuffle(D, d);
                for (int i = 0; i < copy_token; i++){ E[i] = 'O';}
                twoPlayerNim(numberOfTokensInTheGame);

                break;

            case (3):
                cout << "***End of the Game***"<< endl;
                exit(0);

            default:
                break;
        }
    }



void twoPlayerNim(int& numberOfTokensInTheGame) {  // this is the game function for the 2 player game
    cout << "There are " << numberOfTokensInTheGame << " tokens remaining on the heap." << endl;
    checkWinner(numberOfTokensInTheGame, turn); // check if there is a winner
    int tokensToRemove{0};
    showHeaps(A, B, C, D, E);
    (turn == 0 ? cout << "\n\n" << player1 << "'s turn:" << endl : cout << "\n\n" << player2 << "'s turn:" << endl);
    (turn == 0 ? turn = 1 : turn = 0); // ternary to change the turn when the function is called again
    cout << "Please pick a heap to take tokens from: ";
    cin >> heap;
    cout << "\nHow many tokens would you like to take? (1 or 2): ";
    cin >> tokensToRemove;
    switch (heap) {     //switch to assess which heap the user chose and update it
        case 'A':
            if (tokensToRemove != 1 && tokensToRemove != 2) { // if token choice is out of bound!
                cerr << "\nInvalid entry. Please try again" << endl;
                cerr.flush();
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            } else if (heapCheck(A)) {
                heapUpdate(A, tokensToRemove);
                numberOfTokensInTheGame = numberOfTokensInTheGame - tokensToRemove;
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            } else {
                cerr << "\nThere are not enough tokens left in this pile." << endl; cerr.flush();
                (turn == 0 ? turn = 1 : turn = 0);
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            }
            break;
        case 'B':
            if (tokensToRemove != 1 && tokensToRemove != 2) { // if token choice is out of bound!
                cerr << "\nInvalid entry. Please try again" << endl;
                cerr.flush();
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                //(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            } else if (heapCheck(B)) {
                heapUpdate(B, tokensToRemove);
                numberOfTokensInTheGame = numberOfTokensInTheGame - tokensToRemove;
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            } else {
                cout << "\nThere are not enough tokens left in this pile." << endl;
                (turn == 0 ? turn = 1 : turn = 0);
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            }
            break;
        case 'C':
            if (tokensToRemove != 1 && tokensToRemove != 2) { // if token choice is out of bound!
                cerr << "\nInvalid entry. Please try again" << endl;
                cerr.flush();
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            } else if (heapCheck(C)) {
                heapUpdate(C, tokensToRemove);
                numberOfTokensInTheGame = numberOfTokensInTheGame - tokensToRemove;
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            } else {
                cout << "\nThere are not enough tokens left in this pile." << endl;
                (turn == 0 ? turn = 1 : turn = 0);
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            }
            break;
        case 'D':
            if (tokensToRemove != 1 && tokensToRemove != 2) { // if token choice is out of bound!
                cerr << "\nInvalid entry. Please try again" << endl;
                cerr.flush();
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            } else if (heapCheck(D)) {
                heapUpdate(D, tokensToRemove);
                numberOfTokensInTheGame = numberOfTokensInTheGame - tokensToRemove;
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            } else {
                cout << "\nThere are not enough tokens left in this pile." << endl;
                (turn == 0 ? turn = 1 : turn = 0);
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            }
            break;
        case 'E':
            if (tokensToRemove != 1 && tokensToRemove != 2) { // if token choice is out of bound!
                cerr << "\nInvalid entry. Please try again" << endl;
                cerr.flush();
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            } else if (heapCheck(E)) {
                heapUpdate(E, tokensToRemove);
                numberOfTokensInTheGame = numberOfTokensInTheGame - tokensToRemove;
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            } else {
                cout << "\nThere are not enough tokens left in this pile." << endl;
                (turn == 0 ? turn = 1 : turn = 0);
                //checkWinner(numberOfTokensInTheGame, turn);
                return twoPlayerNim(numberOfTokensInTheGame);
            }
            break;
        default:
            //checkWinner(numberOfTokensInTheGame, turn);
            cerr << "Unable to update any heap. Please try again." << endl;
            cerr.flush();
            menu();

    }
}





void PLAYERvsCPU(int& number_of_tokens_in_the_game){
    // when turn is 0, it is the player's turn
    // when turn is 1, it is the CPU's turn
    cout << "There are " << numberOfTokensInTheGame << " tokens remaining on the heap." << endl;
    checkWinner(numberOfTokensInTheGame, turn); // check if there is a winner
    //(turn == 0 ? turn = 1 : turn =0); // ternary to change the turn when the function is called again
    int tokensToRemove{0};
    showHeaps(A, B, C, D, E);
     // ternary to change the turn when the function is called again
    if (turn == 1){
        cout << endl << player2 << "\'s turn"<< endl;
        //CPU
        //generate random numbers between 1 and 2
        tokensToRemove = 1 + (rand() % 2);
        heap = 65 + (rand() % 5); // ascii values for A, B, C, D, E
        cout << "CPU randomly chose heap " << heap << " and " << tokensToRemove << " tokens to remove." << endl;
    }
    else if(turn == 0){
        cout << endl << player1 << "\'s turn"<< endl;
        //player
        cout << "Please pick a heap to take tokens from: ";
        cin >> heap;
        cout << "\nHow many tokens would you like to take? (1 or 2): ";
        cin >> tokensToRemove;
    }
    else
    {cerr << "Something went wrong. Please try again." << endl; EXIT_FAILURE;}

     // end here

    switch (heap) {     //switch to assess which heap the user chose and update it
        case 'A':
            if (tokensToRemove != 1 && tokensToRemove != 2) { // if token choice is out of bound!
                cerr << "\nInvalid entry. Please try again" << endl;
                cerr.flush();
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                return PLAYERvsCPU(numberOfTokensInTheGame);
            } else if (heapCheck(A)) {
                heapUpdate(A, tokensToRemove);
                numberOfTokensInTheGame = numberOfTokensInTheGame - tokensToRemove;
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                return PLAYERvsCPU(numberOfTokensInTheGame);
            } else {
                cerr << "\nThere are not enough tokens left in this pile." << endl; cerr.flush();
                (turn == 0 ? turn = 1 : turn = 0);
                return PLAYERvsCPU(numberOfTokensInTheGame);
            }
            break;
        case 'B':
            if (tokensToRemove != 1 && tokensToRemove != 2) { // if token choice is out of bound!
                cerr << "\nInvalid entry. Please try again" << endl;
                cerr.flush();
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                return PLAYERvsCPU(numberOfTokensInTheGame);
            } else if (heapCheck(B)) {
                heapUpdate(B, tokensToRemove);
                numberOfTokensInTheGame = numberOfTokensInTheGame - tokensToRemove;
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                return PLAYERvsCPU(numberOfTokensInTheGame);
            } else {
                cout << "\nThere are not enough tokens left in this pile." << endl;
                (turn == 0 ? turn = 1 : turn = 0);
                return PLAYERvsCPU(numberOfTokensInTheGame);
            }
            break;
        case 'C':
            if (tokensToRemove != 1 && tokensToRemove != 2) { // if token choice is out of bound!
                cerr << "\nInvalid entry. Please try again" << endl;
                cerr.flush();
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                return PLAYERvsCPU(numberOfTokensInTheGame);
            } else if (heapCheck(C)) {
                heapUpdate(C, tokensToRemove);
                numberOfTokensInTheGame = numberOfTokensInTheGame - tokensToRemove;
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                return PLAYERvsCPU(numberOfTokensInTheGame);
            } else {
                cout << "\nThere are not enough tokens left in this pile." << endl;
                (turn == 0 ? turn = 1 : turn = 0);
                return PLAYERvsCPU(numberOfTokensInTheGame);
            }
            break;
        case 'D':
            if (tokensToRemove != 1 && tokensToRemove != 2) { // if token choice is out of bound!
                cerr << "\nInvalid entry. Please try again" << endl;
                cerr.flush();
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                return PLAYERvsCPU(numberOfTokensInTheGame);
            } else if (heapCheck(D)) {
                heapUpdate(D, tokensToRemove);
                numberOfTokensInTheGame = numberOfTokensInTheGame - tokensToRemove;
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                return PLAYERvsCPU(numberOfTokensInTheGame);
            } else {
                cout << "\nThere are not enough tokens left in this pile." << endl;
                (turn == 0 ? turn = 1 : turn = 0);
                return PLAYERvsCPU(numberOfTokensInTheGame);
            }
            break;
        case 'E':
            if (tokensToRemove != 1 && tokensToRemove != 2) { // if token choice is out of bound!
                cerr << "\nInvalid entry. Please try again" << endl;
                cerr.flush();
                (turn == 0 ? turn = 1 : turn = 0); // this statement switch players!
                return PLAYERvsCPU(numberOfTokensInTheGame);
            } else if (heapCheck(E)) {
                heapUpdate(E, tokensToRemove);
                numberOfTokensInTheGame = numberOfTokensInTheGame - tokensToRemove;
                (turn == 0 ? turn = 1 : turn = 0);
                return PLAYERvsCPU(numberOfTokensInTheGame);
            } else {
                cout << "\nThere are not enough tokens left in this pile." << endl;
                (turn == 0 ? turn = 1 : turn = 0);
                return PLAYERvsCPU(numberOfTokensInTheGame);
            }
            break;
        default:
            //checkWinner(numberOfTokensInTheGame, turn);
            cerr << "Unable to update any heap. Please try again. Returning to main menu! " << endl;
            cerr.flush();
            menu();

    }
}

