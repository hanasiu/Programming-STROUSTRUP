#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<typename ln, typename Out>
Out copy_(ln first, ln last, Out res) {
    while (first != last) {
        *res = *first;
        ++res;
        ++first;
    }
    return res;
}

int main() {
    // ostream_iterator<string> oo{cout};

    // **oo = "Hello, ";
    // ++oo;
    // *oo = "World!\n";

    // istream_iterator<string> ii{cin};

    // string s1 = *ii;
    // ++ii;
    // string s2 = *ii;

    string from, to;
    cin >> from >> to;

    ifstream is {from};
    ofstream os {to};

    istream_iterator<string> ii {is};
    istream_iterator<string> eos;
    ostream_iterator<string> oo {os, "\n"};

    vector<string> b {ii, eos};
    sort(b.begin(), b.end());
    copy_(b.begin(), b.end(), oo); 

//     vector<string> c {5};
//     copy_(ii, eos, c.begin());
}