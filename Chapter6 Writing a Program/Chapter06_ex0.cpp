#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h" // header provided by author // https://www.stroustrup.com/Programming/std_lib_facilities.h


using namespace std;

int charToInt(vector<int> v)
{
    if (v.size() == 0)
        error("empty vector handed to charToInt()");
    if (v.size() > 4)
        error("charToInt can handle only up to four digits");
    int num = 0;
    for (int i = 0; i < v.size(); ++i)
        num = 10 * num + v[i];
    return num;
}

void plural_s(int n)
{
    if (n == 0 || n > 1)
        cout << 's';
    if (n == 1)
        return;
    if(n<0)
        error("plural_s can handle only non-negative numbers");
}

void printNumber(vector<int> v, vector<string> num_words, int num)
{
    if(num>9999||v.size()>4)
        error("print_number can only handle numbers with four digits");
    if(v.size()==0)
        error("print_number was handed an empty vector");
    cout << num << " is ";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << ' ' << num_words[i + 4 - v.size()];
        plural_s(v[i]);
        if (i < v.size() - 1)
            cout << " and ";
    }
    cout << endl;
}

int main() 
try {
    vector<string> numWords;
    numWords.emplace_back("thousand");
    numWords.emplace_back("hundred");
    numWords.emplace_back("ten");
    numWords.emplace_back("one");

    cout << "Enter number with up to four digits.\n";
    cout << "Enter ; to print numbers.\n";
    cout << "Enter 'q' to quit the program.\n";
    while (true)
    {
        vector<int> integer;
        char ch;
        while (cin >> ch)
        {
            if (ch == ';')
                break;
            if (ch == 'q')
                return 0;
            if (ch < '0' || ch>'9')
            {
                cin.ignore(10000, '\n');
                break;
            }
            if (integer.size() > 4)
                error("print_number can only handle numbers up to four digits");
            integer.emplace_back(ch - '0');
        }

        int asInt = charToInt(integer);

        printNumber(integer, numWords, asInt);

        cout << "Try again:\n";
    }
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    keep_window_open();
    return 2;
}
