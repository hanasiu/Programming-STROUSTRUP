#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string a, b, c;
	cout << "Please enter three strings: ";
	cin >> a >> b >> c;
	vector<string> three = { a, b, c };
	sort(three.begin(), three.end());
	for (int i = 0; i < three.size()-1; ++i)
	{
		cout << three[i] << ", ";
	}
	cout << three[2] << ".";

}
