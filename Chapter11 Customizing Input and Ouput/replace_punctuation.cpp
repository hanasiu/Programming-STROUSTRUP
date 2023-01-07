#include "std_lib_facilities.h"


int main()
try {
    string line;
    getline(cin, line);
    for(char& ch:line) 
        switch(ch) {
        case ';': case '.': case ',': case '?': case '!':
            ch = ' ';
    }

    stringstream ss(line);
    vector<string> vs;
    for (string word; ss >> word;)
        vs.push_back(word);
    for (auto i : vs) {
        cout << i << " ";
    }

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
