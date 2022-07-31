#include "std_lib_facilities.h"// header provided by the authour. 
//https://www.stroustrup.com/Programming/std_lib_facilities.h

int main() {
	int val1, val2;
	cin >> val1 >> val2;
	if (val1 > val2)
	{
		cout << "val2(" << val2 << ") is smaller than val1(" << val1 << ")\n";
	}
	else if (val1 < val2)
	{
		cout << "val1(" << val1 << ") is smaller than val2(" << val2 << ")\n";
	}
	else
	{
		cout << "same.\n";
	}
	cout << "sum: " << val1 + val2 << endl;
	int diff = val1 - val2;
	diff > 0 ? diff : diff *= -1;
	cout << "difference: " << diff << endl;
	cout << "product: " << val1 * val2 << endl;
	cout << "ratio of these values: " << (double)val1 / val2 << endl;
}
