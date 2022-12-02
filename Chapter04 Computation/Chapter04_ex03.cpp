#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<double> distance;
	for (double i; cin >> i;)
	{
		distance.emplace_back(i);
	}
	double sum = 0;
	sort(distance.begin(), distance.end());
	for (auto i : distance)
	{
		sum += i;
	}
	cout << "the totla distance: " << sum << endl
		<< "the smallest distance: " << distance[0] << endl
		<< "the greatest distance: " << distance[distance.size() - 1] << endl
		<< "the mean distance: " << sum / distance.size() << endl;
}
