#include "std_lib_facilities.h"

int maxInt(const vector<int>& vec) {
	int max = 0;
	for (auto i : vec) {
		if (i > max) max = i;
	}
	return max;
}
int main()
try {
	vector<int> vec = { 1, 2, 3, 4, 100, 30 };
	int num = maxInt(vec);
	cout << num << endl;
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
