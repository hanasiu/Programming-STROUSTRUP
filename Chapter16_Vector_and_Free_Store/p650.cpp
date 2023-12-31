#include <iostream>

using namespace std;

int main() {
    double ad[10];
    double* p = &ad[5];
    *p = 7;
    p[2] = 6;
    p[-3] = 9;
    cout << p[-3] << endl;;
    p+=2;
    cout << *p << endl;
    *p = 12.34;
    cout << *p << endl;

    return 0;
} 

//clang++ --std=c++14 p650.cpp && ./a.out && rm a.out