#include "std_lib_facilities.h"


enum num_format {
    decimal, octal, hexadecimal
};

ostream& operator<<(ostream& os, num_format nf)
{
    switch (nf) {
    case decimal:
        return os << "decimal\t";
    case octal:
        return os << "octal\t";
    case hexadecimal:
        return os << "hexadecimal\t";
    default:
        error("illegal value of number_format");
    }
}

void printnum(int n, num_format nf)
{
    cout << showbase;
    switch (nf) {
    case decimal:
        cout << dec << setw(10) << n;
        break;
    case octal:
        cout << oct << setw(10) << n;
        break;
    case hexadecimal:
        cout << hex << setw(10) << n;
        break;
    }
    cout << ' ' << nf << "\tconverts to " << dec << setw(6) << n << ' ' << decimal << endl;
}

int main()
try {
    cout << "Enter space-separated integers in decimal, octal or hexadecimal notation" << endl
        << "(using 0 and 0x prefixes), any letter to finish:" << endl;
    int n = 0;
    char ch;
    while (cin >> ch) {
        if (ch == '0') {
            cin.get(ch);
            if (ch == 'x') {
                cin >> hex >> n;
                printnum(n, hexadecimal);
            }
            else if (isdigit(ch)) {
                cin.unget();
                cin >> oct >> n;
                printnum(n, octal);
            }
            else {
                cin.unget();
                printnum(0, octal);
            }
        }
        else if (isdigit(ch)) {
            cin.unget();
            cin >> dec >> n;
            printnum(n, decimal);
        }
        else break;
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
