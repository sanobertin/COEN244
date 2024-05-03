// Created by Bertin Mihigo Sano on 2023-12-03.
//

#include "Nim.h"
using std::cout;


void Nim::pileShuffle(char pile[], int h){ // assigns a random number to an int variable and uses that variable to assign
    h = rng();                        // that amount of tokens to a certain heap array
    for (int i = 0; i < h; i++){
        pile[i] = 'O';
    }
    n = n-h;
}

void Nim::shuffle() { // shuffle tokens into piles of the game
    pileShuffle(A, a);
    pileShuffle(B, b);
    pileShuffle(C, c);
    pileShuffle(D, d);
    for (int i = 0; i < n; i++){ // this just takes the rest of the tokens and assigns them to the last heap
        E[i] = 'O';
    }
}

void Nim::showHeaps(char A[], char B[], char C[], char D[], char E[]){ // displays the heaps
    cout << endl << "A:  ";
    for (int i = 0; i < 20; i++){
        cout << A[i];
    }
    cout << endl << "B:  ";
    for (int i = 0; i < 20; i++){
        cout << B[i];
    }
    cout << endl << "C:  ";
    for (int i = 0; i < 20; i++){
        cout << C[i];
    }
    cout << endl << "D:  ";
    for (int i = 0; i < 20; i++){
        cout << D[i];
    }
    cout << endl << "E:  ";
    for (int i = 0; i < 20; i++){
        cout << E[i];
    }
}

void Nim::printNim() { // prints the game
    showHeaps(A, B, C, D, E);
}


void Nim::tokenChoice(){ // function for the amount of tokens to take from the chosen heap
    std::cout << "\nHow many tokens would you like to take? (1 or 2): ";
    std::cin >> tokens;
}

void Nim::heapChoice(){ // heap selection
    std::cout << "\nPlease pick a heap to take tokens from: ";
    std::cin >> heap;
}

void Nim::numOfTokens(){ //total number of tokens for 2 player game
    std::cout << "\nPlease enter an integer between 10 and 20 for the number of tokens you would like to have: ";
    std::cin >> n;
    if (n < 10 || n > 20){
        std::cout << "\nInvalid entry. Please try again.\n";
        numOfTokens();
    }else std::cout << "\n";
}


bool heapCheck(char Heap[]){
    int length = sizeof(Heap)/sizeof(char); // get the size of the heap
    int howManyTokensRemainingOnAHeap = 0;
    for (int i = 0; i < length; i++){
        if (Heap[i] == 'O'){ // if there is a token in the heap, return true
            howManyTokensRemainingOnAHeap++;
        }
        else { continue;}
    }
    if(howManyTokensRemainingOnAHeap <=2 && howManyTokensRemainingOnAHeap >0)
        return true;
    else
        return false;
}



bool Nim::heapCheck(char Heap[]){
    if ((Heap[0] != 'O' && tokens == 1) || (Heap[1] != 'O' && tokens == 2)){ // boolean used to check if the user is trying to take
        return false;                                                        // more tokens than there are left in the chosen heap
    }
    else return true;
}

int Nim::heapUpdate(char H[]){              //updates the amount of tokens in the heap the user chooses based on the amount of tokens they choose
    int u = tokens;
    for (int i = 20; i >= 0; i--){
        if (H[i] == 'O' && u > 0){
            H[i] = ' ';
            u = u - 1;
        }
    }return tokens;
}