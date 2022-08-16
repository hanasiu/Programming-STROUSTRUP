#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h" // header provided by author // https://www.stroustrup.com/Programming/std_lib_facilities.h


using namespace std;


int main() {
    try {
        double num = 0;
        cout << "Please enter the number of values you want to sum.\n";
        cin >> num;
        if (num < 0) error("Negative number not allowed. Range Underflow.\n");
        double temp = 0, sum = 0;
        vector<double> list;
        vector<double> diffs;
        double diff = 0;
        cout << "Please enter some numbers (press '|' to stop)\n" <<
            "If the number is out of range, program terminates.\n";
        while (cin >> temp&&temp!='|')
        {
            list.emplace_back(temp);
            if (list.size() >= 2)
            {
                diff = temp - list[list.size() - 2];
                diff >= 0 ? diff : diff *= -1;
                diffs.emplace_back(diff);
            }
        }
        cout << "difference list: ";
        if (list.size() <= 1)
        {
            cout << "no diff\n";
        }
        else {
            for (auto i : diffs)
            {
                cout << i << " ";
            }
            cout << endl;
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
                //https://stackoverflow.com/questions/199333/how-do-i-detect-unsigned-integer-overflow
                // `a + x` would overflow
                if (list[i] > 0 && sum > DBL_MAX - list[i]) error("DOUBLE TYPE OVERFLOW!!)");
                // `a + x` would underflow
                if (list[i] < 0 && sum < DBL_MIN - list[i]) error("DOUBLE TYPE UNDERFLOW!!)");
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
