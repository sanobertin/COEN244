// Created by Bertin Mihigo Sano on 2023-10-08.
//

#pragma once
#include <iostream>
class Shape {
private:
    int sideCount {}; // how many sides does a shape have?
    Shape() = default;
    virtual int getSides() = 0;
    virtual void status() final;
    virtual ~Shape() = default;
};


