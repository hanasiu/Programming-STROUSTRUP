#include "std_lib_facilities.h"



int main()
try {
    string command;
    getline(cin, command);
    
    stringstream ss{ command };
    vector<string> words;
    for (string s; ss >> s;) {
        words.push_back(s);
    }

    for (auto i : words) {
        cout << i << " ";
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
