//Chapter09_ex17.cpp
//Chapter09_ex18.cpp
#include "Money.h"
#include "Rational.h"

int main()
try {
    Money m1(5, 12);
    Money m2(100, 2);
    Rational m1toR(512);
    Rational m2toR(1002);

    //cout << m1 / m2; // Not working
    cout << "m1 / m2 is not supported" << endl;
    cout << "m1toR / m2toR: " << m1toR / m2toR << endl;

    double d1 = 10;
    double d2 = 3;
    cout << "d1 / d2: " << d1 / d2 << endl; // not accurate
    Rational d1toR(10);
    Rational d2toR(3);
    cout << "d1toR / d2toR: " << d1toR / d2toR << endl;

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
