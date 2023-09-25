// Created by Bertin Mihigo Sano on 2023-09-15.
//

#include<iostream>

using namespace std;

int main(){
    cout <<" how many courses: ";
    int num;
    cin >> num;
    double marks[num];
    while(num>=0){
        cout <<"Enter "<<num - 4<<" number: ";
        cin >> marks[num-1];
        num--;
        cout << endl;
    }
    double sum, avg;
    for(size_t i: marks){
        sum = sum+ marks[i];
    }
    cout << "Average: "<<avg << endl;
    cout << "Sum: "<<sum<<endl;
}