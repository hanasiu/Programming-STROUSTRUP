#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	double smallest = 0, largest = 0;
	double cur = 0;
	string unit;
	double sum = 0;
	int count = 0;
	double toM = 0;
	bool isFirst = true;
	vector <double> arr;
	cout << "Enter value and unit. unit allowed: cm, m, in, ft.\n";
	while (cin >> cur >> unit)
	{
		if (unit != "cm" && unit != "m" && unit != "in" && unit != "ft")
		{
			cout << "not allowed unit\nunit allowed: cm, m, in, ft\n";
			continue;
		}

		if (unit == "cm")
		{
			toM = cur * 1 / 100;
		}
		else if (unit == "in")
		{
			toM = cur * 1 / 100 * 2.54;
		}
		else if (unit == "ft")
		{
			toM = cur * 1 / 100 * 2.54 * 12;
		} 
		else if (unit == "m")
		{
			toM = cur;
		}

		if (toM < smallest || isFirst)
		{
			smallest = toM;
			isFirst = false;
			cout << "the smallest so far: " << smallest << "m" << endl;
		}
		if (toM > largest)
		{
			largest = toM;
			cout << "the largest so far: " << largest << "m" << endl;
		}
		cout << "current value and unit: " << cur << unit << endl;
		sum += toM;
		++count;
		arr.emplace_back(toM);
	}
	sort(arr.begin(), arr.end());
	cout << "the smallest: " << smallest << "m" << endl
		<< "the largest: " << largest << "m" << endl
		<< "the number of values: " << count << endl
		<< "the sum of values: " << sum << "m" << endl;
	cout << "values: ";
	for (auto i : arr)
	{
		cout << i << " ";
	}
}
