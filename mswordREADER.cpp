// Created by Bertin Mihigo Sano on 2023-11-16.
//
#include <locale>
#include <codecvt>
#include <fstream>
#include <iostream>

using namespace std;
using std::string;

int main() {
    string path_to_file = "/Users/bertin/CLionProjects/COEN244/tutorial.docx";
    string data;
    std::fstream file;
    file.open(path_to_file, std::ios::binary| std::ios::in);
    file.imbue(std::locale("en_US.UTF-8"));
    //cout << file.getloc(). << endl;
    // Open the file using locale with UTF16 encoding

    ///file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff>()));
                      //     new std::codecvt_utf16<wchar_t, 0x10ffff, std::consume_header>));std::consume_header

    if (file.is_open()) {
        while(!file.eof()) {
            file >> data;
            std::cout << data << std::endl;
        }
    } else {
        // Handle the error
    }

    file.close();
    return 0;
}