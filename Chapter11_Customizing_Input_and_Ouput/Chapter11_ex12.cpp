#include "std_lib_facilities.h"


int main()
try {
    cout << "Enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ifs(iname.c_str());
    if (!ifs) error("can't open input file ", iname);
    cout << "Enter output file name: ";
    string oname;
    cin >> oname;
    ofstream ofs(oname.c_str());
    if (!ofs) error("can't open output file ", oname);

    // read file into string
    string contents;
    char ch;
    while (ifs.get(ch))
        contents.push_back(ch);

    // read string from end, write into file
    for (int i = contents.length() - 1; i >= 0; --i) {
        ofs << contents[i];
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
