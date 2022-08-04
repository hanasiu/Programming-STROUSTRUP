#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<double> temps;
	for (double temp; cin >> temp;)
	{
		temps.emplace_back(temp);
	}
	
	sort(temps.begin(), temps.end());

	if (temps.size() % 2 == 1)
	{
		cout << "Median temperature: " << temps[temps.size() / 2] << endl;
	}
	else if (temps.size() % 2 == 0)
	{
		cout << "Median temperature: " <<
			(temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2 << endl;
	}
}
