// Created by Bertin Mihigo Sano on 2023-11-16.
//


#include <iostream>
#include <string>
#include <cstdlib>ß
using namespace std;

template <typename T>
auto compareless = [](T&a, T&b){
    return a<b;
};
template <typename T>
auto comparehigh = [](T&a, T&b){
    return a>b;
};

vector <int> container;


int main(){
    for(int i = 0; i < 10; ++i) {
        container.push_back(std::rand()%34);
    }
    for_each(container.begin(), container.end(), [](int& a){cout << a << '\t';});
    sort(container.begin(), container.end(), compareless<int>);
    cout << endl;
    for_each(container.begin(), container.end(), [](int& a){cout << a << '\t';});
    cout << endl;
    sort(container.begin(), container.end(), comparehigh<int>);
    for_each(container.begin(), container.end(), [](int& a){cout << a << '\t';});
    cout << endl;
    string A = "Aaron", B="Abron";
    cout <<boolalpha << comparehigh<string>(A, B) << endl;

}