// Created by Bertin Mihigo Sano on 2023-11-12.
// COEN244 - Assignment 4
// STUDENT ID: 40157663

#pragma once
#include "TA.h"
#include "AllExceptions.h"
#include <iostream>
#include <string>
#include <memory>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include<cstdlib>
using std::string;
using std::vector;
using std::fstream;
using std::stringstream;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::ios;
using std::clog;


namespace utilities{
    void addNewTA(vector<TA>& add_into_this_container);
    vector<TA> loadSavedTAs(string& path);
    void saveTAs(string& path, const vector<TA>& data);
    void MySort(vector<TA>& container_to_sort);
    void ValidateTAs(vector<TA>& container);
    void clear_screen();
    void hold();
}




void utilities::addNewTA(vector<TA>& add_into_this_container) {
    try {
        cout << endl;
        int id;
        int year;
        string status;
        int age;
        string in;
        // ask to enter a new TA
        cout << "TA\'s Student ID: ";
        cin >> in;
        id = stoi(in);
        in = "";

        for (const TA &TA: add_into_this_container) {
            if (TA.getStudentID() == id) {
                cerr << "Error: Student ID already exists." << endl;
                cerr.flush();
                hold();
                return; // exit the function
            }
        }
        cout << "Year hired: ";
        cin >> in;
        year = stoi(in);
        in = "";
        cout << "Status: (Alum, Grad, UGrad): ";
        cin >> status;
        cout << "Age: ";
        cin >> in;
        age = stoi(in);
        in = "";
        add_into_this_container.emplace_back(id, year, status, age);
        cout << "New TA added successfully!" << endl;
        hold();
        return;
    }
    catch (IException &err) {cerr << err.what() << endl; cerr.flush();}
    catch(OException& e){cerr << e.what() << endl;}
    catch(FailedToAllocateMemory& e){e.what();}
    catch(std::ios_base::failure& e){cerr << "Error: wrong input data type." << endl; cerr.flush();}
    catch (std::bad_alloc& e){cerr << "Error: " << "bad alloc error!" << endl;cerr.flush();}
    catch (std::out_of_range& e){cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (std::exception& e){cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (BadRange &e) {e.what();}
    catch (BadInputDataType &e) {e.what();}
    catch (std::out_of_range &e) {cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (std::bad_exception &e) {cerr << "Error: " << e.what() << endl;cerr.flush();}
}



// sample function description
vector<TA> utilities::loadSavedTAs(string& path) {
    try {
        vector<TA> loadedTAs;
        fstream reader(path, ios::in);
        if (reader.is_open()) {
            string txt_file_line;
            int line_counter = 1;
            while (getline(reader, txt_file_line)) {
                if (txt_file_line.empty()) continue; // skip empty lines
                if (line_counter == 1) { // first line
                    int TAsCount = stoi(txt_file_line);
                    clog << "Number of TAs on disk: " << TAsCount << endl;
                    clog.flush();
                    loadedTAs.reserve(TAsCount);
                    line_counter++;
                    continue; // skip to the rest of the loop
                }
                stringstream ss(txt_file_line);
                string substr;
                int subcounter = 1;
                int id, year, age;
                string status;
                while (!ss.eof()) { // This loop will read each line and store the values in the TA object
                    ss.flush();
                    switch (subcounter) {
                        case 1:
                            ss >> id;
                            break;
                        case 2:
                            ss >> year;
                            break;
                        case 3:
                            ss >> status;
                            break;
                        case 4:
                            ss >> age;
                            break;
                        default:
                            throw IException("Error reading line " + txt_file_line + " due to formatting issue\n");
                    }
                    subcounter++;
                }
                status.erase(std::remove(status.begin(), status.end(), ' '),
                             status.end()); // clean status as it might contain spaces
                loadedTAs.emplace_back(id, year, status,
                                       age); // create new TA object and store it into the vector of loaded TAs
                line_counter++;
            }

            clog << "Number of TAs loaded: " << loadedTAs.size() << endl;
            clog.flush();


        } else {
            throw IException("Error opening file " + path + " Please check file/directory\n");
        }
        reader.close();
        return loadedTAs;
    }
    catch (IException &err) {cerr << err.what() << endl; cerr.flush();}
    catch(OException& e){cerr << e.what() << endl;}
    catch(FailedToAllocateMemory& e){e.what();}
    catch(std::ios_base::failure& e){cerr << "Error: wrong input data type." << endl; cerr.flush();}
    catch (std::bad_alloc& e){cerr << "Error: " << "bad alloc error!" << endl;cerr.flush();}
    catch (std::out_of_range& e){cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (std::exception& e){cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (BadRange &e) {e.what();}
    catch (BadInputDataType &e) {e.what();}
    catch (std::out_of_range &e) {cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (std::bad_exception &e) {cerr << "Error: " << e.what() << endl;cerr.flush();}
}




//Save TAs to a file
void utilities::saveTAs(string& path, const vector<TA>& data){
    try {
        fstream writer(path, ios::out);
        if (writer) {
            writer << data.size() << endl;
            for (auto &TA: data) {
                writer << TA.getStudentID() << '\t' << TA.getYearHired() << '\t' << TA.getStatus() << '\t'
                       << TA.getAge() << endl;
            }
        } else {
            throw OException("Unable to save on " + path + ". Please check file/directory\n");
        }

        writer.close();
        clog << "datas saved successfully on " << path << endl;
        clog.flush();
    }
    catch (IException &err) {cerr << err.what() << endl; cerr.flush();}
    catch(OException& e){cerr << e.what() << endl;}
    catch(FailedToAllocateMemory& e){e.what();}
    catch(std::ios_base::failure& e){cerr << "Error: wrong input data type." << endl; cerr.flush();}
    catch (std::bad_alloc& e){cerr << "Error: " << "bad alloc error!" << endl;cerr.flush();}
    catch (std::out_of_range& e){cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (std::exception& e){cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (BadRange &e) {e.what();}
    catch (BadInputDataType &e) {e.what();}
    catch (std::out_of_range &e) {cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (std::bad_exception &e) {cerr << "Error: " << e.what() << endl;cerr.flush();}
}
// end of saveTAs function definition

// Remove all TAs with "alumni" status function definition

void utilities::ValidateTAs(vector<TA>& container){
    try {
        for (size_t t = 0; t < container.size(); ++t) {
            string i = container[t].getStatus(); // i is the status of the TA
            if (i.find("Alum") != string::npos || i.find("alum") != string::npos || i.find("ALUM") != string::npos) {
                vector<TA>::iterator iter = {container.begin() + t};
                cout << "Removing TA: ";
                container[t].printTA();
                container.erase(iter);
            } else { continue; } // skip to the iteration
        }
    }
    catch (IException &err) {cerr << err.what() << endl; cerr.flush();}
    catch(OException& e){cerr << e.what() << endl;}
    catch(FailedToAllocateMemory& e){e.what();}
    catch(std::ios_base::failure& e){cerr << "Error: wrong input data type." << endl; cerr.flush();}
    catch (std::bad_alloc& e){cerr << "Error: " << "bad alloc error!" << endl;cerr.flush();}
    catch (std::out_of_range& e){cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (std::exception& e){cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (BadRange &e) {e.what();}
    catch (BadInputDataType &e) {e.what();}
    catch (std::out_of_range &e) {cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (std::bad_exception &e) {cerr << "Error: " << e.what() << endl;cerr.flush();}
}



void utilities::MySort(vector<TA>& container_to_sort) {
    try {
        int from, to, col;
        auto beginIter = container_to_sort.begin();
        cout << "The database contains " << container_to_sort.size() << " TAs" << endl;
        cout << "Enter the range of TAs to sort. Between 1 and " << container_to_sort.size() << " : " << endl;
        cout << "From: ";
        cin >> from;
        cout << "To: ";
        cin >> to;
        char order;
        if (from <= 0 || to > container_to_sort.size()) {
            throw BadRange(
                    "Invalid range. The range  must be between 1 and " + std::to_string(container_to_sort.size()) +
                    "\n");
        } else {
            cout << "Enter the column to sort by: " << endl;
            cout << "1. Student ID\t 2. Year Hired\t 3. Status\t 4. Age" << endl;
            cin >> col;
            if (col >= 1 && col <= 4) {
                cout << "Ascending or Descending order? (a/d): ";
                cin >> order;
                if (order == 'a' || order == 'A') { // ascending order
                    switch (col) {
                        case 1:
                            sort(beginIter + from-1, beginIter + to-1, [](const TA &a, const TA &b) {
                                return (a < b);
                            }); // by default, compares by student ID
                            break;
                        case 2:
                            sort(beginIter + from-1, beginIter + to-1, [](const TA &a, const TA &b) {
                                return (a.getYearHired() < b.getYearHired());
                            });
                            break;
                        case 3:
                            sort(beginIter + from-1, beginIter + to-1, [](const TA &a, const TA &b) {
                                return (a.getStatus() < b.getStatus());
                            });
                            break;
                        case 4:
                            sort(beginIter + from-1, beginIter + to-1, [](const TA &a, const TA &b) {
                                return (a.getAge() < b.getAge());
                            });
                            break;
                        default:
                            throw BadInputDataType("Invalid column. Please try again.\n");
                            break;
                    }
                } else if (order == 'd' || order == 'D') { // descending order
                    switch (col) {
                        case 1:
                            sort(beginIter + from-1, beginIter + to-1, [](const TA &a, const TA &b) {
                                return (a > b);
                            });
                            break;
                        case 2:
                            sort(beginIter + from-1, beginIter + to-1, [](const TA &a, const TA &b) {
                                return (a.getYearHired() > b.getYearHired());
                            });
                            break;
                        case 3:
                            sort(beginIter + from-1, beginIter + to-1, [](const TA &a, const TA &b) {
                                return (a.getStatus() > b.getStatus());
                            });
                            break;
                        case 4:
                            sort(beginIter + from-1, beginIter + to-1, [](const TA &a, const TA &b) {
                                return (a.getAge() > b.getAge());
                            });
                            break;
                        default:
                            throw BadInputDataType("Invalid column. Please try again.\n");
                    }
                } else {
                    throw BadRange("Invalid order. The order must be either \'a\' or \'d\'\n");
                }
            } else {
                throw BadRange("Invalid column. The column must be between 1 and 4\n");
            }
            //end of order selection
        }
        // end of column selection
    }
    catch (IException &err) {cerr << err.what() << endl; cerr.flush();}
    catch(OException& e){cerr << e.what() << endl;}
    catch(FailedToAllocateMemory& e){e.what();}
    catch(std::ios_base::failure& e){cerr << "Error: wrong input data type." << endl; cerr.flush();}
    catch (std::bad_alloc& e){cerr << "Error: " << "bad alloc error!" << endl;cerr.flush();}
    catch (std::out_of_range& e){cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (std::exception& e){cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (BadRange &e) {e.what();}
    catch (BadInputDataType &e) {e.what();}
    catch (std::out_of_range &e) {cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (std::bad_exception &e) {cerr << "Error: " << e.what() << endl;cerr.flush();}
}




// end of sort function definition


void utilities::clear_screen(){
#ifdef _WIN32
    std::system("cls");
#elif __APPLE__ || __MACH__ || __linux__
    std::system ("clear");

#endif

}

void utilities::hold(){
    try {
        cout << "Press enter key to return to the system menu...";
        cin.get();
        cin.ignore();
    }
    catch (IException &err) {cerr << err.what() << endl; cerr.flush();}
    catch(OException& e){cerr << e.what() << endl;}
    catch(FailedToAllocateMemory& e){e.what();}
    catch(std::ios_base::failure& e){cerr << "Error: wrong input data type." << endl; cerr.flush();}
    catch (std::bad_alloc& e){cerr << "Error: " << "bad alloc error!" << endl;cerr.flush();}
    catch (std::out_of_range& e){cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (std::exception& e){cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (BadRange &e) {e.what();}
    catch (BadInputDataType &e) {e.what();}
    catch (std::out_of_range &e) {cerr << "Error: " << e.what() << endl;cerr.flush();}
    catch (std::bad_exception &e) {cerr << "Error: " << e.what() << endl;cerr.flush();}
}




