#pragma once
#include "std_lib_facilities.h"

int gcd(int a, int b)
{
	while (b != 0) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

class Rational {
public:
	Rational(): numerator{0}, denominator{1} { }
	Rational(int n): numerator{n}, denominator{1} { }
	Rational(int n, int d) : numerator{ n }, denominator{ d } { normalize(); }


	int getNum() const { return numerator; }
	int getDen() const { return denominator; }
	double toDouble() const { return double(numerator) / denominator; }

	void normalize()
	{
		if (denominator == 0) error("denominator is zero");
		if (denominator < 0) { denominator = -denominator; numerator = -numerator; }
		int n = gcd(numerator, denominator);
		if (n > 1) { numerator /= n; denominator /= n; }
	}

private:
	int numerator;
	int denominator;
};

Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);
bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);
ostream& operator<<(ostream& os, const Rational& r);

Rational operator+(const Rational& r1, const Rational& r2)
{
	Rational r(r1.getNum() * r2.getDen() + r1.getDen() * r2.getNum(), r1.getDen() * r2.getDen());
	r.normalize();
	return r;
}

Rational operator-(const Rational& r1, const Rational& r2)
{
	Rational r(r1.getNum() * r2.getDen() - r1.getDen() * r2.getNum(), r1.getDen() * r2.getDen());
	r.normalize();
	return r;
}

Rational operator*(const Rational& r1, const Rational& r2)
{
	Rational r(r1.getNum() * r2.getNum(), r1.getDen() * r2.getDen());
	r.normalize();
	return r;
}


Rational operator/(const Rational& r1, const Rational& r2)
{
	Rational r(r1.getNum() * r2.getDen(), r1.getDen() * r2.getNum());
	r.normalize();
	return r;
}

bool operator==(const Rational& r1, const Rational& r2)
{
	return r1.getNum() * r2.getDen() == r1.getDen() * r2.getNum();
}

bool operator!=(const Rational& r1, const Rational& r2)
{
	return !(r1 == r2);
}

ostream& operator<<(ostream& os, const Rational& r)
{
	return cout << '(' << r.getNum() << '/' << r.getDen() << ')';
}
