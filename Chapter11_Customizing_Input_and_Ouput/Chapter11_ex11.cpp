#include "std_lib_facilities.h"


vector<string> split(const string& s)
{
    istringstream is(s);
    string ss;
    vector<string> substrings;
    while (is >> ss) substrings.push_back(ss);
    return substrings;
}

bool contains(const string& s, char ch)
{
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == ch) return true;
    return false;
}
vector<string> split(const string& s, const string& w)
{
    string ss = s;
    for (int i = 0; i < ss.size(); ++i) {
        for (int j = 0; j < w.size(); ++j) {
            if (contains(w, ss[i])) ss[i] = ' ';
        }
    }
    return split(ss);
}

// print vector of strings
void print_vec(const vector<string> vs)
{
    for (int i = 0; i < vs.size(); ++i)
        cout << vs[i] << endl;
}

int main()
try {
    cout << "Enter string with separation characters: ";
    string w;
    getline(cin, w);
    cout << "Enter a few words: ";
    string s;
    while (getline(cin, s)) {
        vector<string> substrings = split(s, w);
        cout << "\nYou entered:\n";
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
