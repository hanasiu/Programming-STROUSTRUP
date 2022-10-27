#pragma once
#include "std_lib_facilities.h"

class Patron {
public:
	string getName() const { return name; }
	string getCardNum() const { return cardNum; }
	double getFee() const { return fee; }

	double setFee(double f);
private:
	string name;
	string cardNum;
	double fee;

};

double Patron::setFee(double f)
{
	if (f < 0) error("setFee(): fee cannot be smaller than zero");
	fee = f;
}

bool oweFee(const Patron& p)
{
	return p.getFee() > 0;
}