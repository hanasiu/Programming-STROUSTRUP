#include "std_lib_facilities.h"

double caculSum(const vector<double>& price, const vector<double>& weight) {
	if (price.size() != weight.size()) error("Size is different!");
	double sum = 0;
	for (int i = 0; i < price.size(); ++i) {
		sum += price[i] * weight[i];
	}
	return sum;
}

int main()
try {
	vector<double> price = { 10.1, 30.2, 40.5, 100.1, 90 };
	vector<double> weight = { 10, 20, 30.5, 9.99, 30 };
	double sum = caculSum(price, weight);
	cout << sum << endl;
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
