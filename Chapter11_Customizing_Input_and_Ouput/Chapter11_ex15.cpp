#include "std_lib_facilities.h"


int main()
try {
    cout << "Enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ifs(iname.c_str());
    if (!ifs) error("can't open input file ", iname);

    // read numbers
    double d;
    vector<double> nums;
    while (ifs >> d)
        nums.push_back(d);

    // print numbers in given format
    cout << scientific << setprecision(8);
    for (int i = 0; i < nums.size(); ++i) {
        cout << setw(20) << nums[i];
        if ((i + 1) % 4 == 0) cout << endl;
    }

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
