#include <iostream>

using namespace std;

void f(int i, double fpd) {
    char c = i;
    short s =i;
    i = i+1;
    long lg = i*i;
    float fps = fpd;
    i = fpd;
    fps = i;
}

void g() {
    char ch = 0;
    for(int i =0; i<500; ++i) {
        cout << int(ch++) << '\t';
    }
}

void check_numeric_limits() {
    cout << sizeof(int) << endl;
    cout << sizeof(double) << endl;
    cout << INT_MAX << endl;
    cout << numeric_limits<int>::min() << endl;
    if(numeric_limits<char>::is_signed) 
    cout << "signed" << endl;
    else 
    cout << "unsigned" << endl;

    char ch = numeric_limits<char>::min();
    cout << ch << endl;
    cout << int(ch) << endl;
}

int main() {
    //g();
    check_numeric_limits();
    return 0;
}