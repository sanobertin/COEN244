// Created by Bertin Mihigo Sano on 2023-11-12.
// COEN244 - Assignment 4
// STUDENT ID: 40157663

#include "TA.h"




TA::TA(const TA& rhs) // copy constructor
    : studentID(rhs.studentID), yearHired(rhs.yearHired), status(rhs.status), age(rhs.age){} // copy constructor


TA::TA(int id, int year, string status, int age) // TA constructor
    :studentID(id), yearHired(year), status(status), age(age){}
/*
TA& TA::operator=(const TA& rhs) { // copy assignment operator
    TA obj(rhs.studentID, rhs.yearHired, rhs.status, rhs.age);
    return obj;
}
 */


string TA::getStatus() const {
    return this->status;
}

int TA::getStudentID() const {
    return this->studentID;
}

int TA::getYearHired() const {
    return this->yearHired;
}
int TA::getAge() const {
    return this->age;
}

void TA::printTA() const {
    std::cout << "ID:" << studentID << std::setw(15)<<"Year:" << yearHired << std::setw(15)<<"Status:" << status << std::setw(15)<<"Age:" << age ;
    std::cout << std::endl;
}


bool TA::operator<(const TA& rhs) const{
    return studentID < rhs.studentID;

}
bool TA::operator>(const TA& rhs) const{
    return studentID > rhs.studentID;
}

