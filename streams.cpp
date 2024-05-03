
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    char* myinput;
    stringstream  sstr;
    sstr <<"Hello!" << '\t';
    cout <<"Before flushed: " << sstr.str() << endl;
    sstr.str("");
    sstr.clear();
    
    cout <<"Flushed: " << sstr.str() << endl;
    EXIT_SUCCESS;
}