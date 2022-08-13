#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h" // header provided by author // https://www.stroustrup.com/Programming/std_lib_facilities.h

using namespace std;

double ctof(double c)
{
	if (c < -273.15) error("Temperature below absolute zero!");
	double f = (c * 9.0 / 5.0) + 32;
	return f;
}

double ftoc(double f)
{
	if (f < -459.67) error("Temperatur below absolute zero!");
	double c = (f - 32) * 5.0 / 9.0;
	return c;
}

int main() {
	try {
		double temp = 0;
		cin >> temp;
		char unit = ' ';
		cin >> unit;
		double dest = 0;
		if (unit == 'c' || unit == 'C')
		{
			dest = ctof(temp);
			cout << dest << "°F\n";
		}
		else if (unit == 'f' || unit == 'F')
		{
			dest = ftoc(temp);
			cout << dest << "°C\n";
		}
		else
		{
			error("unit not matched, must be C or F");
		}
		return 0;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "Unknown exception!\n";
		return 2;
	}
}
