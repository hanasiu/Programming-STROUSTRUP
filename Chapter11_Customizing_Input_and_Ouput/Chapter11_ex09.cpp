#include "std_lib_facilities.h"

const string bin_file = "bin.dat";   // name of binary file

void to_binary(const string& s)
{
    ifstream ifs(s.c_str());
    if (!ifs) error("can't open input file ", s);
    ofstream ofs(bin_file.c_str(), ios_base::binary);
    if (!ofs) error("can't open output file ", bin_file);

    char ch;
    while (ifs.get(ch)) {
        ofs.write(as_bytes(ch), sizeof(ch));
    }
}

void from_binary(const string& s)
{
    ofstream ofs(s.c_str());
    if (!ofs) error("can't open output file ", s);
    ifstream ifs(bin_file.c_str(), ios_base::binary);
    if (!ifs) error("can't open input file ", bin_file);

    char ch;
    while (ifs.read(as_bytes(ch), sizeof(char))) {
        ofs << ch;
    }
}

int main()
try {
    cout << "Enter input file name: ";
    string iname;
    cin >> iname;
    to_binary(iname);

    cout << "Enter output file name: ";
    string oname;
    cin >> oname;
    from_binary(oname);

    cout << "Done!\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
