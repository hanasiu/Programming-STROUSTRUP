#include <iostream>

using namespace std;

int main() {
	int num;
	cout << "Please enter a integer: ";
	while (cin >> num) {
		if (num % 2)
		{
			cout << "The value " << num << " is an odd number.\n";
		}
		else
		{
			cout << "The value " << num << " is an even number.\n";
		}
	}
}
