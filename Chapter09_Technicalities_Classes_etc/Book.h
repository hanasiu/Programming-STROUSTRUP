#pragma once
#include "std_lib_facilities.h"

class Book {
public:
	enum Genre {
		fiction = 0, nonfiction, periodical, biography, children
	};

	// constructors
	Book(string ISBN, string title, string author, int date, Genre gen, bool checkedOut);
	Book(); // default constructor

	string getISBN() const { return ISBN; }
	string getTitle() const { return title; }
	string getAuthor() const { return author; }
	string getCopyrightDate() const { return copyrightDate; }
	Genre genre() const { return gen; }
	bool isCheckedOut() const { return checkedOut; }

	void checkOut();
	void checkIn();

	bool validISBN();

private:
	string ISBN;
	string title;
	string author;
	string copyrightDate;
	Genre gen;
	bool checkedOut;
};

void Book::checkOut()
{
	if (isCheckedOut()) error("already checked out");
	checkedOut = true;
}

void Book::checkIn()
{
	if (!isCheckedOut()) error("already checked in");
	checkedOut = false;
}

bool Book::validISBN()
{
	for (int i = 0; i < ISBN.size(); ++i) {
		if (ISBN[i] < 0 || ISBN[i]>9 || ISBN[i] != '-') return false;
	}
	return true;
}

bool operator==(const Book& b1, const Book& b2)
{
	return (b1.getISBN() == b2.getISBN());
}

bool operator!=(const Book& b1, const Book& b2)
{
	return !(b1 == b2);
}

ostream& operator<<(ostream& os, const Book& b)
{
	return os << b.getTitle() << endl
		<< b.getAuthor() << endl
		<< b.getISBN() << endl;
}


