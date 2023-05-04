//https://github.com/bewuethr/stroustrup-ppp/blob/main/chapter06/chapter06_ex06.cpp
/*
 Sentence:
		Subject Verb
		Sentence Conjunction Sentence
		Subject:
			Noun
			"the" Noun
		Conjunction:
			"and"
			"or"
			"but"
		Noun:
			"birds"
			"fish"
			"C++"
		Verb:
			"rules"
			"fly"
			"swim"
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "std_lib_facilities.h"

using namespace std;

class String_stream {
public:
	String_stream();
	string get();
	void putback(string s);
private:
	bool full;
	string buffer;
};

String_stream::String_stream()
	:full(false), buffer("") { }

void String_stream::putback(string s)
{
	if (full) error("putback() into a full buffer");
	buffer = s;
	full = true;
}

string String_stream::get()
{
	if (full) {
		full = false;
		return buffer;
	}

	string s = "";
	cin >> s;
	return s;
}

String_stream sstr;

// checks if next string is a conjunction
bool conjunct()
{
	string s = sstr.get();
	if (s == "and" || s == "or" || s == "but")
		return true;
	else
		return false;
}

// checks if a string is a noun
bool noun()
{
	string s = sstr.get();
	if (s == "birds" || s == "fish" || s == "C++")
		return true;
	else
		return false;
}

// checks if a string is a verb
bool verb()
{
	string s = sstr.get();
	if (s == "rules" || s == "fly" || s == "swim")
		return true;
	else
		return false;
}

//handles subjects
bool subject()
{
	string s = sstr.get();
	if (s == "the")
		return noun();
	else {
		sstr.putback(s);
		return noun();
	}
}

//handles sentences
bool sentence()
{
	return (subject() && verb());
}

int main()
try {
	bool is_ok = false;
	while (true) {
		is_ok = sentence();
		if (!is_ok) {
			cout << "Not OK\n";
			return 0;
		}
		string s = sstr.get();
		if (s == ".") {
			cout << "OK\n";
			return 0;
		}
		else {
			sstr.putback(s);
			is_ok = conjunct();
			if (!is_ok) {
				cout << "Not OK\n";
				return 0;
			}
		}

	}
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}
