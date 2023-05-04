#include "std_lib_facilities.h"


double str_to_double(string s)
{
    istringstream is{ s };
    double d;
    is >> d;
    if (!is) error("double format error: ", s);
    return d;
}



int main()
try {
    double d1 = str_to_double("12.4");
    double d2 = str_to_double("1.34e-3");
    //double d3 = str_to_double("twelve point three");
    cout << d1 << " " << d2;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
