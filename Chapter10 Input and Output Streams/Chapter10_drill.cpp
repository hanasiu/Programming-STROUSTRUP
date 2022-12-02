#include "std_lib_facilities.h"

struct Point {
	int x;
	int y;
	Point(): x(0), y(0) { }
	Point(int xx, int yy): x(xx), y(yy) { }
};

bool operator==(const Point& p1, const Point& p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(const Point& p1, const Point& p2)
{
	return !(p1 == p2);
}

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

void write_to_file(const vector<Point>& points, const string& name)
{
	ofstream ost(name.c_str());
	if (!ost) error("can't open output file ", name);
	for (int i = 0; i < points.size(); ++i) {
		ost << points[i] << endl;
	}
}

void fill_from_file(vector<Point>& points, const string& name)
{
	ifstream ist(name.c_str());
	if (!ist) error("can't open input file, ", name);
	Point pp;
	while (ist >> pp) points.emplace_back(pp);
}

void compare_vectors(const vector<Point>& points1, const vector<Point>& points2)
{
	if (points1.size() != points2.size())
		error("Something's wrong about size!");
	for (int i = 0; i < points1.size(); ++i) {
		if (points1[i] != points2[i]) {
			error("somethin's wrong about value!");
		}
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

	string filename = "drill.txt";
	write_to_file(original_points, filename);

	vector<Point> processed_points;
	fill_from_file(processed_points, filename);

	cout << "\nData from ifstream:\n";
	print_vector(processed_points);
	cout << "\nOriginal data:\n";
	print_vector(original_points);

	compare_vectors(original_points, processed_points);
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
