#include <regex>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in{"zipcode.txt"};
    if (!in)
        cerr << "no file\n";

    regex pat{R"(\w{2}\s*\d{5}(–\d{4})?)"}; // postal code pattern
    int lineno = 0;
    for (string line; getline(in, line);)
    { // read input line into input buffer
        ++lineno;
        smatch matches; // matched strings go here if (regex_search(line, matches, pat))
        if (regex_search(line, matches, pat))
            cout << lineno << ": " << matches[0] << '\n';
    }

    //     for (string line; getline(in,line); ) {
    //         smatch matches;
    // if (regex_search(line, matches, pat)) {
    // cout << lineno << ": " << matches[0] << '\n'; if (1<matches.size() && matches[1].matched)
    // cout << "\t: " << matches[1] << '\n';
    // } }
}