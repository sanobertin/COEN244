#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <filesystem>
#include <array>
using namespace std;
array <string, 4> extractRow(string arg);


int main(){
    //cout.flush();
    clog <<endl<<"The system is currently running on folder: "<<filesystem::current_path()<<endl;
    string status = "UGrad";
    string name = "Abdulla";
    int id = 5788200;
    int year = 2019;
    string ss = status+TAB+name+  TAB+ to_string(id)+TAB+ to_string(year);
    array<string, 4> getFromLine = extractRow(ss);
    cout << getFromLine[0] << endl;
    cout << getFromLine[1] << endl;
    cout << getFromLine[2] << endl;
    cout << getFromLine[3] << endl;

    return 0;
}


