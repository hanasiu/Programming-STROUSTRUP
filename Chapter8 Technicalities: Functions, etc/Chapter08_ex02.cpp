#include "std_lib_facilities.h"

using namespace std;

void print(string label, const vector<int> vec) {
	cout << label << " (" << vec.size() << "): {";
	for (int i = 0; i < vec.size(); ++i) {
		if (i % 10 == 0) cout << endl;
		cout << vec[i] ;
		if (i < vec.size() - 1) cout << ", ";
	}
	cout << "}\n";
}

bool findMaxInt(int x, int y) {
	return x > y;
}

void fibonacci(int x, int y, vector<int>& vec, int num) {
	vec.reserve(num);
	if (num < 1) error("there must be at least one number in the series");
	vec.emplace_back(x);
	if (num == 1) return;
	vec.emplace_back(y);
	for (int i = 2; i < num; ++i) {
		vec.emplace_back(vec[i - 2] + vec[i - 1]);
		if (findMaxInt(vec[i - 2], vec[i - 1])) {
			cout << "Max Int is " << vec[i - 2] << endl;
			vec.erase(vec.end() - 2, vec.end());
			break;
		}
	}
}

int main() 
try {
	vector<int> instance = {};
	int first = 1;
	int second = 2;
	int num = 1;
	while (true) {
		cout << "Enter three number" << endl
			<< "first and second number, and how many fibonacci numbers do you want?" << endl;
		cin >> first >> second >> num;
		fibonacci(first, second, instance, num);
		print("Fibonacci List", instance);
	}
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
