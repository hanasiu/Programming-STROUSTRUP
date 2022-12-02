#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c;
	cout << "Please enter three integers: ";
	cin >> a >> b >> c;
	vector<int> three = { a, b, c };
	sort(three.begin(), three.end());
	for (int i = 0; i < three.size()-1; ++i)
	{
		cout << three[i] << ", ";
	}
	cout << three[2] << ".";

}
