#include "std_lib_facilities.h"


int main()
try {
    cout << "Enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ifs(iname.c_str());
    if (!ifs) error("can't open input file ", iname);

    // read numbers
    int n;
    vector<int> numbers;
    while (ifs >> n)
        numbers.push_back(n);

    //sort and print
    sort(numbers.begin(), numbers.end());
    int counter = 1; 
    //cout << numbers[0];
    for (int i = 0; i < numbers.size(); ++i) {
        if (i == 0 || numbers[i] != numbers[i - 1]) {
            if (counter > 1) cout << "\t" << counter;
            cout << endl;
            counter = 1;
            cout << numbers[i];
        }
        else ++counter;
    }
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
