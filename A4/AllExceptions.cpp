// Created by Bertin Mihigo Sano on 2023-11-12.
// COEN244 - Assignment 4
// STUDENT ID: 40157663

#include "AllExceptions.h"

// Exceptions for file read
IException::IException(char *errorMsg) : errorMsg((char *) errorMsg) {}

const char *IException::what() const noexcept {
    std::cerr << "Error: " << errorMsg << std::endl;    // print error message
    return  errorMsg;
}

IException::IException(std::string &&errorMsg)  {
    std::cerr << "Error: " << errorMsg << std::endl;std::cerr.flush();// print error message
    std::strcpy(this->errorMsg, errorMsg.c_str());
}

// Exceptions for file write
OException::OException(char *errorMsg) : errorMsg((char *) errorMsg) {}

const char *OException::what() const noexcept {
    std::cerr << "Error: " << errorMsg << std::endl;  std::cerr.flush();  // print error message
    return  errorMsg;
}

OException::OException(std::string &&errorMsg)  {
    std::cerr << "Error: " << errorMsg << std::endl; std::cerr.flush();// print error message
    std::strcpy(this->errorMsg, errorMsg.c_str());
}


// Exceptions for bad input data type
BadInputDataType::BadInputDataType(std::string &&dataType) : dataType((char *) dataType.c_str()) {};

const char *BadInputDataType::what() const noexcept {
    std::cerr << "Error: " << dataType << " is not a valid data type for this input" << std::endl;   std::cerr.flush(); // print error message
    return  dataType;
}


// throw if user enters a value out of range of expected values
BadRange::BadRange(char *errorMsg) : range_error(errorMsg), errorMsg(errorMsg) {}
BadRange::BadRange(std::string &&errorMsg) : range_error((char *) errorMsg.c_str()), errorMsg((char *) errorMsg.c_str()) {}

const char *BadRange::what() const noexcept {
    std::cerr << "Error: " << errorMsg << std::endl;   std::cerr.flush();  // print error message
    return  errorMsg;
}

FailedToAllocateMemory::FailedToAllocateMemory(char *errorMsg) : bad_alloc(), errorMsg(errorMsg) {}
FailedToAllocateMemory::FailedToAllocateMemory(std::string &&errorMsg) : bad_alloc(), errorMsg((char *) errorMsg.c_str()) {}

const char *FailedToAllocateMemory::what() const noexcept {
    std::cerr << "Error: " << errorMsg << std::endl;   std::cerr.flush();// print error message
    return  errorMsg;
}

//
