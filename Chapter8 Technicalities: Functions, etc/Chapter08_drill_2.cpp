#include "std_lib_facilities.h"

void swap_v(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << a << " " << b << endl;
} 

void swap_r(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
	cout << a << " " << b << endl;
}

void swap_cr(const int& a, const int& b) {
	int temp;
	temp = a;
	// a = b; // error
	// b = temp; //error
}

int main() {
	int x = 7;
	int y = 9;
	swap_r(x, y);
	cout << x << " " << y << endl;
	cout << "**********" << endl;
	swap_v(7, 9);
	cout << "**********" << endl;
	const int cs = 7;
	const int cy = 9;
	//swap_ ? (cx, cy);
	swap_v(7.7, 9.9);
	cout << "**********" << endl;
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx, dy); // compiler not allow swap_r(dx, dy);
	cout << dx << " " << dy << endl;
	cout << "**********" << endl;
	swap_v(7.7, 9.9);
	return 0;
}
