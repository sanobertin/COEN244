// Created by Bertin Mihigo Sano on 2023-11-12.
// COEN244 - Assignment 4
// STUDENT ID: 40157663



#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using std::string;

class TA {
private:
    int studentID;
    int yearHired;
    string status;
    int age;
public:
    TA(int id, int year, string status, int age);
    TA(const TA& rhs); // copy constructor
    //TA& operator=(const TA& rhs); //assignment operator overload
    //~TA();
    int getStudentID() const;
    int getYearHired() const;
    string getStatus() const;
    int getAge() const;
    void printTA() const;
    bool operator<(const TA& rhs) const;
    bool operator>(const TA& rhs) const;

};



