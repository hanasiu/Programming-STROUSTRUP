#include "std_lib_facilities.h"

using namespace std;

void print(string label, const vector<string> vec) {
	cout << label << " (" << vec.size() << "): {";
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i];
		if (i < vec.size() - 1) cout << ", ";
	}
	cout << "}\n";
}

vector<string> reverseNew(const vector<string> vec) {
	vector<string> reverse = {};
	for (int i = vec.size()-1; i >= 0; --i) {
		reverse.emplace_back(vec[i]);
	}
	return reverse;
}

void reverseElement(vector<string>& vec) {
	for (int i = 0, j = vec.size() - 1; i < j; ++i, --j) {
		swap(vec[i], vec[j]);
	}
}

int main() 
try {
	vector<string> vec = { "happy", "birth", "day", "to", "you"};
	vector<string> vec2 = { "my", "name", "is", "kim", "cheol", "su"};
	vector<string> vec3 = reverseNew(vec);
	print("vec3", vec3);
	reverseElement(vec);
	print("reverse vec", vec);
	reverseElement(vec2);
	print("reverse vec2", vec2);
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}
