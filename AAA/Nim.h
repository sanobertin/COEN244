
#pragma once
#include<iostream>
#include<random>
using std::endl;

class Nim {
private:
    std::string player1, player2;
    int n{0};
    int numOfPlayers{0};
    int turn{0};
    int tokens{0};
    int a, b, c, d;
    char A[20], B[20], C[20], D[20], E[20];
    void pileShuffle(char pile[], int h);
    void showHeaps(char A[], char B[], char C[], char D[], char E[]);

public:
    void shuffle();
    void printNim();
    void tokenChoice();
    void heapChoice();
    void numOfTokens();
    bool heapCheck(char Heap[]);
    int heapUpdate(char H[]);
};





char heap;
std::string player1, player2;

int rng(){     //Random number generator for the 2 player game heaps
    std::random_device generator;
    std::uniform_int_distribution<int> distro(1,n/2);
    return distro(generator);
}

void players() {   //game mode selection
    std::cout << "\n1 or 2 players?:\n ";
    std::cin >> numOfPlayers;
}


int twoPlayerNim(int count, int check){  // this is the game function for the 2 player game

    showHeaps(A, B, C, D, E);
    (turn == 0 ? std::cout << "\n\n"  << player1 << "'s turn:"<<endl: std::cout << "\n\n" << player2 <<"'s turn:"<<endl);
    (turn == 0 ? turn = 1 : turn = 0); // ternary to change the turn when the function is called again
    heapChoice();
    tokenChoice();
    switch (heap){     //switch to assess which heap the user chose and update it
        case 'A':

            if (tokens != 1 && tokens != 2){std::cout << "\nInvalid entry. Please try again"<<endl;(turn == 0 ? turn = 1 : turn = 0);
                return twoPlayerNim(count, check);}
            else if(heapCheck(A)) {heapUpdate(A);}
            else {
                std::cout << "\nThere are not enough tokens left in this pile."<<endl;
                (turn == 0 ? turn = 1 : turn = 0); // ternary to undo the change at the beginning of the function for when a user enters
                return twoPlayerNim(count, check);  // something that isn't valid. this way it's still their turn
            }                                       // that ternary shows up a few more times whenever I made a fail-safe for invalid entries
            break;
        case 'B':

            if (tokens != 1 && tokens != 2){std::cout << "\nInvalid entry. Please try again"<<endl;(turn == 0 ? turn = 1 : turn = 0);
                return twoPlayerNim(count, check);}
            else if(heapCheck(B)) {heapUpdate(B);}
            else {
                std::cout << "\nThere are not enough tokens left in this pile."<<endl;
                (turn == 0 ? turn = 1 : turn = 0);
                return twoPlayerNim(count, check);
            }
            break;
        case 'C':

            if (tokens != 1 && tokens != 2){std::cout << "\nInvalid entry. Please try again"<<endl;(turn == 0 ? turn = 1 : turn = 0);
                return twoPlayerNim(count, check);}
            else if(heapCheck(C)) {heapUpdate(C);}
            else {
                std::cout << "\nThere are not enough tokens left in this pile."<<endl;
                (turn == 0 ? turn = 1 : turn = 0);
                return twoPlayerNim(count, check);
            }
            break;
        case 'D':

            if (tokens != 1 && tokens != 2){std::cout << "\nInvalid entry. Please try again"<<endl;(turn == 0 ? turn = 1 : turn = 0);
                return twoPlayerNim(count, check);}
            else if(heapCheck(D)) {heapUpdate(D);}
            else {
                std::cout << "\nThere are not enough tokens left in this pile."<<endl;
                (turn == 0 ? turn = 1 : turn = 0);
                return twoPlayerNim(count, check);
            }
            break;
        case 'E':

            if (tokens != 1 && tokens != 2){std::cout << "\nInvalid entry. Please try again"<<endl;(turn == 0 ? turn = 1 : turn = 0);
                return twoPlayerNim(count, check);}
            else if(heapCheck(E)) {heapUpdate(E);}
            else {
                std::cout << "\nThere are not enough tokens left in this pile."<<endl;
                (turn == 0 ? turn = 1 : turn = 0);
                return twoPlayerNim(count, check);
            }
            break;
        default:
            std::cout << "\nInvalid entry. Please try again."<<endl;
            (turn == 0 ? turn = 1 : turn = 0);
            return twoPlayerNim(count, check);
    }//the ternary under this was necessary because without it the token counter would lag behind by a turn and the game wouldn't end properly
    (count == check ? count = count - tokens : count = count);
    if (count > 1){return twoPlayerNim(count- tokens, check);}  //Here is the recursive function call
    else if(count <= 1 && turn == 0){
        showHeaps(A, B, C, D, E);
        std::cout << "\n\n"<< player2 << " WINS!!";
        return 0;
    }
    else {
        showHeaps(A, B, C, D, E);
        std::cout << "\n\n"<< player1 << " WINS!!";
        return 0;
    }

}