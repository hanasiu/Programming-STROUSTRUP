#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h" // header provided by author // https://www.stroustrup.com/Programming/std_lib_facilities.h

using namespace std;

double caculOne(double a, double b, double c)
{
    if ((b * b - 4 * a * c) < 0) error("Imaginary number is too hard for me\n");
    double x1 = (-1 * b + sqrt(b * b - 4 * a * c)) / 2 * a;
    return x1;
}

double caculTwo(double a, double b, double c)
{
    if ((b * b - 4 * a * c) < 0) error("Imaginary number is too hard for me\n");
    double x2 = (-1 * b - sqrt(b * b - 4 * a * c)) / 2 * a;
    return x2;
}

int main() {
    try {
        cout << "ax^2+bx+c=0" << endl
            << "enter a, b, c. then I'll give you x." << endl;
        double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
        while (cin >> a >> b >> c)
        {
            x1 = caculOne(a, b, c);
            x2 = caculTwo(a, b, c);
            cout << "x1: " << x1 << endl
                << "x2: " << x2 << endl;
        }
        return 0;
    }
    catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Unknown exception!\n";
        return 2;
    }
}
