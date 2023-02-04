#include "std_lib_facilities.h"


vector<string> split(const string& s)
{
    istringstream is(s);
    string ss;
    vector<string> substrings;
    while (is >> ss) substrings.push_back(ss);
    return substrings;
}

void print_vec(const vector<string> vs)
{
    for (int i = 0; i < vs.size(); ++i)
        cout << vs[i] << endl;
}

int main()
try {
    cout << "Enter a few words: ";
    string s;
    while (getline(cin, s)) {
        vector<string> substrings = split(s);
        cout << "\nYou entered: \n";
        print_vec(substrings);
        cout << "\nAnother try: ";
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
