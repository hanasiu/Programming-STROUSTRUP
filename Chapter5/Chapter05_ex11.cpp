#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h" // header provided by author // https://www.stroustrup.com/Programming/std_lib_facilities.h


using namespace std;


int main() {
    try {
        int fibo1 = 1, fibo2 = 1;
        int fiboN = 0;
        vector<int> fiboList = { 1, 1 };
        while (true)
        {
            if (fibo2 > INT_MAX - fibo1) { break; }
            fiboN = fibo1 + fibo2;
            fiboList.emplace_back(fiboN);
            fibo1 = fibo2;
            fibo2 = fiboN;
        }
        cout << "Do you want to look up max fibo int?" << endl <<
            "if you want it, please enter 'y' or 'Y'.\n";
        string answer = " ";
        cin >> answer;
        if (answer == "y" || answer == "Y")
        {
            cout << "Max int fibo: " << fiboN;
            return 0;
        }
        cout << "How many Fibonacci series?\n";
        int num = 0;
        cin >> num;
        if (num > fiboList.size())
        {
            error("You want more than max size!!!! Range overflow!\n");
        }
        for (int i = 0; i < num; ++i)
        {
            cout << fiboList[i] << " ";
        }
        cout << endl;

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
