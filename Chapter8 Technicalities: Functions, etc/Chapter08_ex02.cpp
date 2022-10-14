#include "std_lib_facilities.h"

void print(string label, const vector<int> vec) {
	cout << label << " (" << vec.size() << "): {";
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] ;
		if (i < vec.size() - 1) cout << ", ";
	}
	cout << "}\n";
}

void fibonacci(int x, int y, vector<int>& vec, int num) {
	vec.reserve(num);
	if (num < 1) error("there must be at least one number in the series");
	vec.emplace_back(x);
	if (num == 1) return;
	vec.emplace_back(y);
	for (int i = 2; i < num; ++i) {
		vec.emplace_back(vec[i - 2] + vec[i - 1]);
	}
}

int main() {
	vector<int> instance = {};
	int first = 1;
	int second = 2;
	int num = 1;
	while (true) {
		cout << "Enter three number" << endl
			<< "first and second number, and how many fibonacci numbers do you want?" << endl;
		cin >> first >> second >> num;
		fibonacci(first, second, instance, num);
		print("fibonacci", instance);
	}
	return 0;
}
