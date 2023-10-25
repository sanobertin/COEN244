// Created by Bertin Mihigo Sano on 2023-10-14.
//
// The driver CPP
#include <iostream>
#include <string>
#include "Othello.h"

//Track all function definitions here


void loadGame();

void newGame(){
    using namespace std;
    cout << "Starting Positions:" << endl;
    cout << "1. Standard Starting Positions" << endl;
    cout << "2. Four-by-Four Starting Position" << endl;

}
int main(){
    using namespace std;
    cout << "Othello menu" << endl;
    cout <<"1. Load a game" << endl;
    cout << "2. Quit" << endl;
    cout << "3. Start a new game"<< endl;
    /*
    int option;
    switch(option){
        case 1:
            cout << "Game filename:";
            string filename;
            cin >> filename;
            //loadGame(filename);
            // do something
            break;
        case 2:
            cout << "Ending the game here.." << endl;
            exit(EXIT_SUCCESS);
            // do something
            break;
        case '3':
            // do something
            newGame();
            break;
        default:
            cerr << "Invalid option. Try again" << endl;
    }
     */
}