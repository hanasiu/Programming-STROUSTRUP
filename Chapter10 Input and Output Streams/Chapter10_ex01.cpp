#include "std_lib_facilities.h"

void read_ints(vector<int>& ints, const string& name)
{
    ifstream ist(name.c_str());
    if (!ist) error("can't open input file ", name);
    int n;
    while (ist >> n) ints.emplace_back(n);
}

int get_sum(const vector<int>& v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    return sum;
}

int main() 
try {
    cout << "Enter file name: ";
    string iname;
    cin >> iname;
    vector<int> ints;
    read_ints(ints, iname);
    int sum = get_sum(ints);
    cout << "Sum of integers in " << iname << " is " << sum << ".\n";
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
