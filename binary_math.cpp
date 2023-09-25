// Created by Bertin Mihigo Sano on 2023-09-04.
//
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    cout << typeid(*argv).name() << endl;
    cout << argc << endl;

    return 0;
}