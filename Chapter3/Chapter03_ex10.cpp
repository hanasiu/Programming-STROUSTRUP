#include <iostream>

using namespace std;

int main() {
	string operation;
	double num1, num2;
	cout << "Please enter a operation, num1, num2 in order.\n operations: +, -, *, /, plus, minus, mul, and div.\n";
	while (cin >> operation >> num1 >> num2)
	{
		if (operation == "+" || operation == "plus")
		{
			cout << "num1 + num2: " << num1 + num2 << endl;
		} 
		else if (operation == "-" || operation == "minus")
		{
			cout << "num1 - num2: " << num1 - num2 << endl;
		}
		else if (operation == "*" || operation == "mul")
		{
			cout << "num1 * num2: " << num1 * num2 << endl;
		}
		else if (operation == "/" || operation == "div")
		{
			cout << "num1 / num2: " << num1 / num2 << endl;
		}
	}
}
