#include <iostream>

using namespace std;

int main() {
	string number;
	while (cin >> number)
	{
		if (number == "one")
		{
			cout << 1 << endl;
		}
		else if (number == "two")
		{
			cout << 2 << endl;
		}
		else if (number == "three")
		{
			cout << 3 << endl;
		}
		else if (number == "four")
		{
			cout << 4 << endl;
		} 
		else
		{
			cout << "I only know 1, 2, 3, 4.\n";
		}
	}
}
