#include "std_lib_facilities.h"

void print_until_s(vector<string> v, string quit) 
{
	for (int i = 0; i<v.size(); ++i) {
		if (v[i] == quit) return;
		cout << v[i] << endl;
	}
}

void print_until_ss(vector<string> v, string quit)
{
	int counter = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == quit)
			if (counter == 1) return;
			else ++counter;
		cout << v[i] << endl;
	}
}

int main()
try {
	vector<string> vec = { "haha", "kim", "lee", "park", "kim", "koo"};
	print_until_s(vec, "kim");
	cout << "*************" << endl;
	print_until_ss(vec, "kim");
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
