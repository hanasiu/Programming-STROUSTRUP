#include "std_lib_facilities.h"

struct Point {
	int x;
	int y;
	Point(): x(0), y(0) { }
	Point(int xx, int yy): x(xx), y(yy) { }
};

istream& operator>>(istream& is, Point& p)
{
	int x, y;
	char c1, c2, c3;
	is >> c1 >> x >> c2 >> y >>  c3;
	if (!is) return is;
	if (c1 != '(' || c2 != ',' || c3 != ')') {
		is.clear(ios_base::failbit);
		return is;
	}
	p = Point(x, y);
	return is;
}

ostream& operator<<(ostream& os, const Point& p)
{
	return os << '(' << p.x << ',' << p.y << ')';
}

void print_vector(const vector<Point>& points)
{
	for(int i = 0; i < points.size(); ++i) {
		cout << points[i] << endl;
	}
}

int main() 
try {
	vector<Point> original_points;
	cout << "Input seven (x,y) pairs" << endl;
	for (int i = 0; i < 7; ++i) {
		Point p;
		cin >> p;
		original_points.emplace_back(p);
	}

	cout << "\nthe data in original points\n";
	print_vector(original_points);

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
