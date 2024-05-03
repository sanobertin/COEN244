#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class AnyType>
auto less_than_or_equal_to = [](AnyType& a, AnyType& b){return a <= b;};
template<class AnyType>
auto greater_than_or_equal_to = [](AnyType& a, AnyType& b){return a >= b;};

int main(){
    vector<double> numbers;
    for(int i = 0; i < 20; i++){
        numbers.emplace_back((std::rand()%100) / 3.14 );
    }
    for(auto i : numbers){
        cout << i << endl;
    }
    std::sort(numbers.begin(), numbers.end(), less_than_or_equal_to<double>);
    cout<< endl << "After sorting" << endl;
    for(auto i : numbers){
        cout << i << endl;
    }
    return 0;
}
