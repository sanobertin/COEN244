// Created by Bertin Mihigo Sano on 2023-11-12.
// COEN244 - Assignment 4
// STUDENT ID: 40157663


#pragma once
#include <exception>
#include <string>
#include <iostream>
#include <stdexcept>
using std::string;


class IException : public std::exception { // file read exception class
private:
    char* errorMsg;
public:
    explicit IException(char *errorMsg);
    explicit IException(string&& errorMsg);
    const char* what() const noexcept override;
};

class OException : public std::exception { // file write exception class
private:
    char* errorMsg;
public:
    explicit OException(char* errorMsg);
    explicit OException(string&& errorMsg);
    const char* what() const noexcept override;

};

class BadInputDataType : public std::exception { // file write exception class
    // to be thrown when the user enters a wrong data type of any input!
private:
    char* dataType;
public:
    explicit BadInputDataType(string&& dataType);
    const char* what() const noexcept override;

};

class BadRange : public std::range_error {
    // throw if user enters a value out of range of expected values
private:
    char* errorMsg;
public:
    explicit BadRange(char *errorMsg);
    explicit BadRange(std::string &&errorMsg);
    const char* what() const noexcept override;

};

class FailedToAllocateMemory : public std::bad_alloc {
private:
char* errorMsg;
public:
    explicit FailedToAllocateMemory(char *errorMsg);
    explicit FailedToAllocateMemory(std::string &&errorMsg);
    const char* what() const noexcept override;
};




