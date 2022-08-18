#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h" // header provided by author // https://www.stroustrup.com/Programming/std_lib_facilities.h


using namespace std;


void print(vector<int>& vect)
{
    int sum = 0;
    for (auto i : vect) 
    {
        cout << i << " ";
        if (sum > INT_MAX - i) error("INT TYPE RANGE OVERFLOW!!!!");
        sum += i;
        
    }
    cout << "\nsum: " << sum << endl;
}

int main() {
    try {
        vector<int> mon = {};
        vector<int> tue = {};
        vector<int> wed = {};
        vector<int> thur = {};
        vector<int> fri = {};
        vector<int> sat = {};
        vector<int> sun = {};
        string day = " ";
        int value;
        int rejected = 0;
        cout << "Enter the Day of the week and its value. \n" <<
            "if you want to stop, enter 'stop' on the day or enter 'q' on the value\n";
        while (true)
        {
            cin >> day >> value;
            if (value == 0) error("INTEGER TYPE INPUT ERROR!!!");
            std::transform(day.begin(), day.end(), day.begin(), ::tolower);
            if (day == "monday" || day == "mon") mon.emplace_back(value);
            else if (day == "tuesday" || day == "tue" || day == "tues") tue.emplace_back(value);
            else if (day == "wednesday" || day == "wed") wed.emplace_back(value);
            else if (day == "thursday" || day == "thur" || day == "thurs") thur.emplace_back(value);
            else if (day == "friday" || day == "fri") fri.emplace_back(value);
            else if (day == "saturday" || day == "sat") sat.emplace_back(value);
            else if (day == "sunday" || day == "sun") sun.emplace_back(value);
            else ++rejected;
            if (day == "stop" || value == 'q') { if (rejected != 0) { --rejected; }  break; }
            day = " ";
            value = 0;
        }
        cout << "Monday: "; print(mon);
        cout << "Tuesday: "; print(tue);
        cout << "Wednesday: "; print(wed);
        cout << "Thursday: "; print(thur);
        cout << "Friday: "; print(fri);
        cout << "Saturday: "; print(sat);
        cout << "Sunday: "; print(sun);
        cout << "The number of rejected value: " << rejected;
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
