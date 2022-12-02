#include "std_lib_facilities.h"

namespace X {
	int var;
	void print()
	{
		cout << var << endl;
	}
}

namespace Y {
	int var;
	void print()
	{
		cout << var << endl;
	}
}

namespace Z {
	int var;
	void print()
	{
		cout << var << endl;
	}
}

int main() {
	X::var = 7;
	X::print();
	using namespace Y;
	var = 9;
	print(); // Y
	{
		using Z::var;
		using Z::print;
		var = 11;
		print(); //Z
	}
	print(); // Y
	X::print();
	return 0;
}
