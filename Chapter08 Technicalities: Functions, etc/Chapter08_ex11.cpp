#include "std_lib_facilities.h"

struct numbers {
	double max;
	double min;
	double mean;
	double median;
};

numbers getNumbers(vector<double>& vec) {
	double dmax = std::numeric_limits<double>::min(); // minimum value
	double dmin = std::numeric_limits<double>::max();
	double sum = 0;
	for (auto i : vec) {
		if (i > dmax) dmax = i;
		if (i < dmin) dmin = i;
		sum += i;
	}
	numbers example;
	example.max = dmax;
	example.min = dmin;
	example.mean = sum / vec.size();
	sort(vec.begin(), vec.end());
	if (vec.size() % 2 == 1) example.median = vec[vec.size() / 2];
	else example.median = (vec[vec.size() / 2] + vec[vec.size() / 2 - 1]) / 2;
	return example;
}
int main()
try {
	vector<double> vec = { 100.2, 3.2, 2.2, 4.2, 1.2, 40 };
	numbers numberOne = getNumbers(vec);
	cout << "Max is " << numberOne.max << endl
		<< "Min is " << numberOne.min << endl
		<< "Mean is " << numberOne.mean << endl
		<< "Median is " << numberOne.median << endl;
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
