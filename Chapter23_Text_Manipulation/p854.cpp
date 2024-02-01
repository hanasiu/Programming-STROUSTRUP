#include <iostream>
#include <stdexcept>
#include <sstream>


using namespace std;

template<typename Target, typename Source>
Target to(Source arg) {
    stringstream interpreter;
    Target result;

    if((!(interpreter << arg))
    ||!(interpreter>>result) 
    ||!(interpreter>>std::ws).eof()) {
        throw runtime_error{"to<>() failed"};
    }
    return result;
}


int main() {
    try {
        // Test case 1: Convert string to int
        string strValue = "123";
        int intValue = to<int>(strValue);
        cout << typeid(intValue).name() << " Converted int value: " << intValue << endl;

        // Test case 2: Convert double to string
        double doubleValue = 45.67;
        string strDoubleValue = to<string>(doubleValue);
        cout << typeid(strDoubleValue).name() << " Converted string value: " << strDoubleValue << endl;
        

        // Add more test cases as needed...

    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
    }

    return 0;
}