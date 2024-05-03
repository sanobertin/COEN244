// Created by Bertin Mihigo Sano on 2023-09-15.
//
#include <iostream>
#include <complex>

using namespace std;
using namespace std::complex_literals;

int main(){
    complex<double> i = (3i);
    cout << typeid(i).name()<<endl;
    cout << sizeof(i) << endl;
    cout << i << endl;
}
