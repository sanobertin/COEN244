// Created by Bertin Mihigo Sano on 2023-09-18.
// MyStudentID: 40157663
#pragma once
#include <string>

const std::string TAB {"    "}; // TAB specifier
//const int max_TAs {100}; // max number of TAs

class TA {
private:
    std::string Status;
    std::string First_Name;
    int Student_Id;
    int Year_Hired;
public:
    TA(std::string, std::string, int, int);
    std::string getStatus() const;
    std::string getFirst_Name() const;
    int getStudent_Id() const;
    int getYear_Hired() const;
    void printTA() const;

};

