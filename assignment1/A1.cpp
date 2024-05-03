// Created by Bertin Mihigo Sano on 2023-09-18.
// MyStudentID: 40157663
#include "TA.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <regex>
using namespace std;

array <string, 4> extractRow(string arg); // paarg a string and return an array for 4 strings : Status //First_Name //Student_Id //Year_Hired//
vector<TA> readFile(const string arg1); // accept file location and return container of TAs. see TA class
void saveFile(const string arg2, const vector<TA> TA_container);


int main(){
    cout <<"\t*****Assignment 1*****\t"<<endl;
    cout <<"Type in the full path of the TAs.txt file: ";
    string f_location; // location of the TAs.txt file
    cin >>f_location;

    vector<TA> TAs = readFile(f_location); // container to store all TAs
    cout << "Details of all TAs:"<<endl;
    for(TA iter: TAs){ // print all TAs
        iter.printTA();
    }
    cout << endl;
    cout << "Do you want to remove all TAs with \"Alum\" status ?? Y or N" << endl;
    char response;
    cin >> response;
    if(response == 'Y' or response == 'y'){
       for(int t = 0; t<TAs.size();t++){
           if(TAs[t].getStatus()=="Alum"){
               TAs.erase(TAs.begin()+t);
           }
       }
    }

    // print reduced TA
    clog << "We now have "<<TAs.size()<<" TAs."<< endl;
    for(TA it: TAs){ // print all TAs
        it.printTA();
    }
    saveFile(f_location, TAs);
    cout <<"\n Thank you for using our program bye bye!!!\n";
    return 0;
}



// function definition
array <string, 4> extractRow(string arg){
    regex key(TAB);
    sregex_iterator found = sregex_iterator(arg.begin(), arg.end(), key);
    sregex_iterator end = sregex_iterator();
    int foundTABS = distance(found,end); // must be 3 for a complete line
    array<string, 4> line;
    int looper = 0;
    for(int i=0; i<foundTABS+1;++i) {
        if(looper==3){
            line[looper] = arg;
            break;
        }; // terminate loop if this variable goes above line.size !
        if (regex_search(arg, key)) { // condition is met if arg contains TAB
            int TABstartPosition = arg.find(TAB);
            line[looper] = arg.substr(0, TABstartPosition);
            arg = arg.substr(TABstartPosition + TAB.size(), arg.size()); // TABstartPosition+TAB.size() with space removed
        }
        looper++; // +1 position on the array
    }


    return line;
}


vector<TA> readFile(const string arg1){ // arg1 = file location
    vector<TA> returnTAobj;
    fstream reader;
    reader.open(arg1, ios_base::in); // open file in input&output mode
    if(!(reader)){
        // if reading opening file is not succeargful execute below
        cerr<<"Error! Unable to open file "<<arg1<<". Please checked file/folder path\n";
        exit(1);
    }
    else{
        //continue business as usual
        string line;
        int howmanylines = 0;
        while(!reader.eof()) {
            getline(reader, line);
            if (line.size() == 0) { // skip empty lines
                continue;
            }
            else {
                if (howmanylines == 0) {
                    clog << "Your DB contains: " << line << " TAs" << endl << endl;
                    howmanylines++;
                    continue;
                }
                array<string, 4> temp_holder = extractRow(line);
                TA *getTA = new TA(temp_holder[0], temp_holder[1], stoi(temp_holder[2]), stoi(temp_holder[3]));
                howmanylines++;
                returnTAobj.push_back(*getTA); // add new caught TA into the container
                //getTA->printTA();
                delete getTA; // delete memory on each loop
        }
        }
        // reading all TA lines ends here
    }
    reader.close();
    return returnTAobj;
}


void saveFile(const string arg2, const vector<TA> TA_container){ // const to ensure no modification
    // accept save location and container to save
    ofstream writer(arg2);
    writer << TA_container.size() << endl;
    for(auto it: TA_container){ // print all TAs
        writer << it.getStatus()+TAB+it.getFirst_Name()+TAB + to_string(it.getStudent_Id()) + TAB+ to_string(it.getYear_Hired())<<endl;
    }
    writer.close();
}
