// Created by Bertin Mihigo Sano on 2023-11-28.
//
#include <iostream>
using namespace std;
int main(){
    char* c = new char[10];
    cout << c ;
    memset(c, 'A', 4);
    cout << c ;
    cout << endl;
    return 0;
}