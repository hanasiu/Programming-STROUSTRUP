//Chapter05_ex02.cpp
//Chapter05_ex03.cpp
//Chapter05_ex04.cpp
//Chapter05_ex05.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h" // header provided by author // https://www.stroustrup.com/Programming/std_lib_facilities.h

using namespace std;

double ctok(double c)
{
	if (c < -273.15) error("Temperature below absolute zero!");
	double k = c + 273.15;
	return k;
}

double ktoc(double k)
{
	if (k < 0) error("Temperatur below absolute zero!");
	double c = k - 273.15;
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
			dest = ctok(temp);
			cout << dest << "°K\n";
		}
		else if (unit == 'k' || unit == 'K')
		{
			dest = ktoc(temp);
			cout << dest << "°C\n";
		}
		else
		{
			error("unit not matched, must be C or K");
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
