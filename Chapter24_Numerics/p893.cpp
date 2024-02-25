#include <iostream>
#include <iomanip>

using namespace std;

void f(int i, double fpd)
{
    char c = i;
    short s = i;
    i = i + 1;
    long lg = i * i;
    float fps = fpd;
    i = fpd;
    fps = i;
}

void g()
{
    char ch = 0;
    for (int i = 0; i < 500; ++i)
    {
        cout << int(ch++) << '\t';
    }
}

void check_numeric_limits()
{
    cout << sizeof(int) << endl;
    cout << sizeof(double) << endl;
    cout << INT_MAX << endl;
    cout << numeric_limits<int>::min() << endl;
    if (numeric_limits<char>::is_signed)
        cout << "signed" << endl;
    else
        cout << "unsigned" << endl;

    char ch = numeric_limits<char>::min();
    cout << ch << endl;
    cout << int(ch) << endl;
}

void example()
{
    float x = 1.0 / 10;
    float sum = 0;
    for (int i = 0; i < 10; ++i)
        sum += x;
    cout << setprecision(15) << sum << "\n";

    float x = 1.0 / 333;
    float sum = 0;
    for (int i = 0; i < 333; ++i)
        sum += x;
    cout << setprecision(15) << sum << "\n";
}

int main()
{
    // g();
    check_numeric_limits();

    example();

    return 0;
}