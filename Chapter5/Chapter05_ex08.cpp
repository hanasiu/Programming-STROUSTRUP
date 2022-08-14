#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h" // header provided by author // https://www.stroustrup.com/Programming/std_lib_facilities.h


using namespace std;


int main() {
    try {
        int num = 0;
        cout << "Please enter the number of values you want to sum.\n";
        cin >> num;
        if (num < 0) error("Negative number not allowed. Range Underflow.\n");
        int temp = 0, sum = 0;
        vector<int> list;
        cout << "Please enter some integers (press '|' to stop)\n";
        while (cin >> temp&&temp!='|')
        {
            list.emplace_back(temp);
        }
        if (num > list.size())
        {
            error("Too Many: Range Overflow/n");
        }
        else
        {
            cout << "The sum of the first " << num << " numbers ( ";
            for (int i = 0; i < num; ++i)
            {
                cout << list[i] << " ";
                sum += list[i];
            }
            cout << ") is " << sum;
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
