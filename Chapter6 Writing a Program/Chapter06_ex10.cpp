    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include "std_lib_facilities.h" // header provided by author // https://www.stroustrup.com/Programming/std_lib_facilities.h


    using namespace std;

    int factorial(int num)
    {
        if (num < 0) error("no negative number allowed");
        int fact = 1;
        for (int i = 1; i <= num; ++i)
        {
            fact *= i;
        }
        return fact;
    }

    int permutation(int a, int b)
    {
        if (a <= b) error("Too much permutation");
        int per = factorial(a) / factorial(a - b);
        return per;
    }

    int combination(int a, int b)
    {
        int com = permutation(a, b)/factorial(b);
        return com;
    }


    int main() 
        try {
        cout << "enter 'p' for Permutation.\n"
            << "or enter 'c' for Combination.\n";
        while (true) {
            char input;
            cin >> input;
            int a, b;
            if (input == 'p') {
                cout << "You would have 'a' possible numbers. enter 'a';\n"
                    << "You permutate 'b' times. enter 'b'\n";
                cin >> a >> b;
                cout << permutation(a, b) << endl;
            }
            else if (input == 'c') {
                cout << "You would have 'a' possible numbers. enter 'a';\n"
                    << "You combinate 'b' times. enter 'b'\n";
                cin >> a >> b;
                cout << combination(a, b) << endl;
            }
            else cout << "bad input. enter 'p' or 'c'";
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
