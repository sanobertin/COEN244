// Created by Bertin Mihigo Sano on 2023-10-04.
//


#include <iostream>
#include "headers/Shape.h"
using std::cout, std::cin, std::endl;



class Hexagon : public Shape {
private:
    int sideCount = 6;
public:
    ~Hexagon()  = default;
    Hexagon() = default;
    int getSides() override {
        return this->sideCount;
    }


};

class Square : public Shape{
private:
    int sideCount {4};
public:
    ~Square() = default;
    Square() = default;
    int getSides() override{
        return this->sideCount;
    }
};


int main(){
    Hexagon h1();
    h1.status();
    Square sq1();
    cout << h1.getSides() << endl;
    cout << sq1.getSides() << endl;

}