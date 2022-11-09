#pragma once
#include "std_lib_facilities.h"

long int myRound(double d)
{
	return (d > 0.0) ? (d + 0.5) : (d - 0.5);
}

class Money {
public:
	enum Currency {
			USD, WON, YEN
	};

	Money(): cents(0), cur(USD) { }
	Money(long int c): cents(c), cur(USD) { }
	Money(int d, int c) : cents(d * 100 + c), cur(USD)
	{
		if (c >= 100) error("cents must be between 0 and 99");
	}
	Money(long int c, Currency cur): cents(c), cur(cur) { }
	Money(int d, int c, Currency cur)
		:cents(d*100+c), cur(cur) { }

	int getDollars() const { return cents / 100; }
	int getCents() const { return cents % 100; }

	long int cents;
	Currency cur;
};

double exRate(Money::Currency c1, Money::Currency c2)
{
	switch (c1) {
	case Money::USD:
		switch (c2) {
		case Money::WON:
			return 0.0007;
		case Money::YEN:
			return 0.0068;
		default:
			error("exRate: illegal combination of currencies");
		}
	case Money::WON:
		switch (c2) {
		case Money::USD:
			return 1422.0;
		case Money::YEN:
			return 9.64;
		default:
			error("exRate: illegal combination of currencies");
		}
	case Money::YEN:
		switch (c2) {
		case Money::USD:
			return 147.46;
		case Money::WON:
			return 0.10;
		default:
			error("exRate: illegal combination of currencies");
		}
	default:
		error("exRate: illegal combination of currencies");
	}
}

// result in the currency of the first summand
Money operator+(const Money& a, const Money& b)
{
	if (a.cur == b.cur) // just return same currency
		return Money(a.cents + b.cents, a.cur);

	double d = exRate(a.cur, b.cur);

	return Money(a.cents + myRound(d * double(b.cents)), a.cur);
}

Money operator-(const Money& a, const Money& b)
{
	if (a.cur == b.cur) // just return same currency
		return Money(a.cents - b.cents, a.cur);

	double d = exRate(a.cur, b.cur);

	return Money(a.cents - myRound(d * double(b.cents)), a.cur);
}

Money operator-(const Money& m)
{
	return Money(-m.cents, m.cur);
}

Money operator*(int n, const Money& m)
{
	return Money(n * m.cents, m.cur);
}

Money operator*(const Money& m, int n)
{
	return n * m;
}

Money operator/(const Money& m, int n)
{
	if (n == 0) error("division by zero");
	double d = double(m.cents) / n;
	long int c = myRound(d);
	return Money(c, m.cur);
}

ostream& operator<<(ostream& os, const Money::Currency& cur)
{
	switch (cur) {
	case Money::USD:
		return os << "USD";
	case Money::WON:
		return os << "WON";
	case Money::YEN:
		return os << "YEN";
	}
}

ostream& operator<<(ostream& os, const Money& m)
{
	os << m.cur << m.getDollars() << '.';
	if (abs(m.getCents()) < 10) os << '0';      // to get $1.05 instead of $1.5
	os << abs(m.getCents());
	return os;
}

istream& operator>>(istream& is, Money& m)
{
	int d, c;
	string s;
	char ch;
	is >> s >> d >> ch >> c;
	if (!is) return is;
	if (!(s == "USD" || s == "WON" || s == "YEN") || ch != '.') { // oops: format error
		is.clear(ios_base::failbit);                    // set the fail bit
		return is;
	}
	Money::Currency cur;
	if (s == "USD") cur = Money::USD;
	else if (s == "WON") cur = Money::WON;
	else if (s == "YEN") cur = Money::YEN;
	else error("illegal currency in input");
	m = Money(d, (c < 10) ? (10 * c) : c, cur);   // '123.1' means '123.10' and not '123.01'
	return is;
}
