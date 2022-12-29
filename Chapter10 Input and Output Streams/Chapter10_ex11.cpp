#include "std_lib_facilities.h"

bool whitespace(char ch)
{
    return (ch == ' ' || ch == '\t' || ch == '\n');
}


int main()
try {
    string ifname;
    cout << "Enter input file name: ";
    cin >> ifname;
    ifstream ifs(ifname);
    if (!ifs) error("can't open input file", ifname);

    int sum = 0;
    char ch = 0;
    int i = 0;
    int count = 0;

    string s;
    while (ifs >> ch) {
        if (isdigit(ch)) {
            ifs.unget();
            if (ifs >> i) {
                if (ifs.eof() || ifs.get(ch) && whitespace(ch)) {
                    ++count;
                    sum += i;
                    cout << i << endl;
                }
                else {
                    ifs.unget();
                    ifs >> s;
                }
            }
            else error("can't read integer");
        }
        else {
            ifs.unget();
            ifs >> s;
        }
    }
    cout << "sum is " << sum;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
