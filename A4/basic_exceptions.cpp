// Created by Bertin Mihigo Sano on 2023-11-12.
//

#include<iostream>
using namespace std;

void check(){
    bool error = false;
    if(!error){
        throw 8.9f;
    }
}

int main(){
    try {
        check();
    }
    catch (float& potentialError){
        potentialError= potentialError*potentialError;
        cout << "Error: " << potentialError << endl;
    }
    return 0;
}
