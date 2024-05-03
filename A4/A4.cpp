// Created by Bertin Mihigo Sano on 2023-11-12.
// COEN244 - Assignment 4
// STUDENT ID: 40157663

#include "TA.h" // TA class definition
#include <iostream>
#include "Utilities.h" // contains all the functions that are used in this program
#include <vector>
using namespace std;
using namespace utilities; // using the namespace utilities


int main() {
    vector<TA> TAs; // container that stores all TAs
    vector<TA> backup_TAs; // container that stores all TAs loaded from disk as is!
    cout << endl;
    cout << "Welcome to the TA management system." << endl << endl;
    cout << "Enter the location of your \"TAs.txt\" file: ";
    string myfile;
    cin >> myfile;
    // read data from disk
    TAs = loadSavedTAs(myfile);
    backup_TAs = TAs;
    //manipulate string to get backup path
    string backup_path = myfile;
    backup_path.pop_back();
    backup_path.pop_back();
    backup_path.pop_back();
    backup_path.pop_back();
    backup_path.append("_backup.txt");
    //end manipulation here
    while (true) {
        cout << "System menu: " << endl;
        cout << "1. Add a new TA" << endl;
        cout << "2. Sort TAs from.... to ...." << endl;
        cout << "3. Remove All \'Alumni\' students" << endl;
        cout << "4. Show All TAs" << endl;
        cout << "5. Clear screen" << endl;
        cout << "6. Save & Exit" << endl;
        int response_to_menu;
        cin >> response_to_menu;
        switch (response_to_menu) {
            case 1:
                addNewTA(TAs);
                hold();
                break;
            case 2:
                MySort(TAs);
                cout << "TAs sorted successfully!" << endl;
                for_each(TAs.begin(), TAs.end(), [](TA &ta) { ta.printTA(); });
                cout << endl;
                hold();
                break;
            case 3:
                ValidateTAs(TAs);
                hold();
                break;
            case 4:
                clear_screen();
                for_each(TAs.begin(), TAs.end(), [](TA &ta) { ta.printTA(); });
                hold();
                break;
            case 5:
                clear_screen();
                break;
            case 6:
                clog << "Exiting the system..." << endl;
                clog.flush();
                saveTAs(myfile, TAs);
                saveTAs(backup_path, backup_TAs);
                return EXIT_SUCCESS;
            default:
                cerr << "Invalid input. Please try again." << endl;
                cerr.flush();
                break;
        }
    }

// program ends here
return EXIT_SUCCESS;
}