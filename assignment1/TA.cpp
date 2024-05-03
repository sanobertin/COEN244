// Created by Bertin Mihigo Sano on 2023-09-18.
// MyStudentID: 40157663

#include "TA.h"
#include <iostream>


TA::TA(std::string Status, std::string First_Name, int Student_ID, int Year_Hired){
    this->Status = Status;
    this->First_Name = First_Name;
    this->Student_Id = Student_ID;
    this->Year_Hired = Year_Hired;
}

std::string TA::getStatus() const{
    return this->Status;
}
std::string TA::getFirst_Name() const{
    return this->First_Name;
}
int TA::getStudent_Id() const{
    return this->Student_Id;
}
int TA::getYear_Hired() const{
    return this->Year_Hired;
}
void TA::printTA() const {
    std::cout << Status+TAB+First_Name+TAB+ std::to_string(Student_Id) + TAB+ std::to_string(Year_Hired)<<std::endl;

}
