#include "std_lib_facilities.h"

void f(const int a) {
	//++a;
	cout << a << endl;
}

int main()
try {
	int i = 10;
	f(i);
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	return 1;
}
catch (...) {
	cerr << "exception\n";
	return 2;
}
