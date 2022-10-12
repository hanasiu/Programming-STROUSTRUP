/*
Simple calculator
This program implements a basic expression calculator.
Input from cin; output to cout.
The grammar for input is:
Calculation:
	  Statement
	  Print
	  Quit
	  Help
	  Calculation Statement
Statement:
	  Declaration
	  Expression
Declaration:
	  "let" Name "=" Expression
	  "const" Name "=" Expression
Name:
	  letter
	  letter Sequence
Sequence:
	  letter
	  digit
	  "_"
	  letter Sequence
	  digit Sequence
	  "_" Sequence
Print:
	;
	Enter Key
Quit:
	"quit"
Help:
	"help"
Expression:
	Term
	Expression + Term
	Expression - Term
Term:
	Primary
	Term * Primary
	Term / Primary
	Term % Primary
Primary:
	Number
	"(" Expression ")"
	"-" Primary
	"+" Primary
	"sqrt(" Expression ")"
	"pow(" Expression "," Integer ")"
	Name
	Name "=" Expression
Number:
	floating-point-literal
Input comes from cin through the Token_stream called ts.
*/


#include "std_lib_facilities.h"

class Token {
public:
	char kind;
	double value;
	string name;
	Token() : kind{ 0 } { }
	Token(char ch) :kind(ch) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string n) : kind(ch), name(n) { }
};

class Token_stream {

public:
	Token_stream();
	Token_stream(istream&);
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

Token_stream::Token_stream()
	:full(false), buffer(0) { }

const char let = 'L';
const char con = 'C';
const char quit = 'q';
const char help = 'h';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square_root = 's';
const char power = 'p';
const string declkey = "let";
const string constkey = "const";
const string prompt = "> ";
const string result = "= ";
const string sqrtkey = "sqrt";
const string powkey = "pow";
const string helpkey = "help";
const string quitkey = "quit";


Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin.get(ch);
	while (isspace(ch)) {
		if (ch == '\n') return Token(print);  // if newline detected, return print Token
		cin.get(ch);
	}
	switch (ch) {
	case print:
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '=':
	case ',':
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
			cin.putback(ch);
			if (s == declkey) return Token(let);
			if (s == constkey) return Token(con);
			if (s == sqrtkey) return Token(square_root);
			if (s == powkey) return Token(power);
			if (s == helpkey) return Token(help);
			if (s == quitkey) return Token(quit);
			return Token{ name, s };
		}
		error("Bad token");
	}
}

void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;
	full = true;
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}


struct Variable {
	string name;
	double value;
	bool var; // variable (true) or constant (false)
	Variable(string n, double v, bool va = true) :name(n), value(v), var(va) { }
};



class Symbol_table {
public:
	double get(string s);
	void set(string s, double d);
	bool is_declared(string s);
	bool is_let(string s);
	double declare(string s, double val, bool var);

private:
	vector<Variable> var_table;
};

double Symbol_table::get(string s)
{
	for (auto v : var_table)
		if (v.name == s) return v.value;
	error("get: undefined name ", s);
}

void Symbol_table::set(string s, double d)
{
	for (auto v : var_table)
		if (v.name == s) {
			if (v.var) error(s, " is a constant");
			v.value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s)
{
	for (auto v : var_table)
		if (v.name == s) {
			return true;
		}
	return false;
}

bool Symbol_table::is_let(string s)
{
	for (auto v : var_table)
	{
		if (v.name == s && v.var == false) return false;
		if (v.name == s && v.var == true) return true;
	}
}

double Symbol_table::declare(string s, double val, bool var = true)
{
	if (is_declared(s) && !is_let(s))
	{
		error(s, " is const. not delcared twice.");
	}
	else if (is_declared(s) && is_let(s))
	{
		for (auto v : var_table)
		{
			if (v.name == s)
			{
				v.value = val;
				return val;
			}
		}
	}
	var_table.emplace_back(Variable{ s,val,var });
	return val;
}

//Token_stream ts;        // provides get() and putback() 
Symbol_table st;        // provides get(), set(), is_declared() and declare()
double expression(Token_stream& ts);    // declaration so that primary() can call expression()

double my_pow(double base, int expo)
{
	if (expo == 0)
	{
		if (base == 0) return 0;
		return 1;
	}
	double res = base;
	for (int i = 2; i <= expo; ++i)
		res *= base;
	return res;
}

double primary(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression(ts);
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case number:
		return t.value;
	case name: {
		Token next = ts.get();
		if (next.kind == '=') {
			double d = expression(ts);
			st.set(t.name, d);
			return d;
		}
		else {
			ts.putback(next);
			return st.get(t.name);
		}
	}
	case square_root:
	{
		t = ts.get();
		if (t.kind != '(') error("'( expected");
		double d = expression(ts);
		if (d < 0) error("Square roots of negative numbers... nope!");
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return sqrt(d);
	}
	case power:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		double d = expression(ts);
		t = ts.get();
		if (t.kind != ',') error("',' expected");
		t = ts.get();
		if (t.kind != number) error("second argument of 'pow' is not a number.\n Or Sorry. Negative exponents not supported.");
		int i = int(t.value);
		if (i != t.value) error("second argument of 'pow' is not an integer");
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return my_pow(d, i);
	}
	case '-':
		return -primary(ts);

	default:
		error("primary expected");
	}
}

double term(Token_stream& ts)
{
	double left = primary(ts);
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary(ts);
			t = ts.get();
			break;
		case '/':
		{
			double d = primary(ts);
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		case '%':
		{
			double d = primary(ts);
			if (d == 0) error("%: divide by zero");
			left = fmod(left, d);
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

double expression(Token_stream& ts)
{
	double left = term(ts);
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '+':
			left += term(ts);
			t = ts.get();
			break;
		case '-':
			left -= term(ts);
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

double declaration(Token k, Token_stream& ts)
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	double d = expression(ts);
	st.declare(var_name, d, k.kind == let);
	return d;
}

double statement(Token_stream& ts)
{
	Token t = ts.get();
	switch (t.kind) {
	case let: return declaration(false, ts);
	case con: return declaration(true, ts);
	default:
		ts.putback(t);
		return expression(ts);
	}
}

void clean_up_mess(Token_stream& ts)
{
	ts.ignore(print);
}

void print_help()
{
	cout << "Instructions: enter expressions, there are\n";
	cout << "a few functions, you can declare variables using\n";
	cout << "the 'let' keyword and constants with the 'const'\n";
	cout << "keyword.\n";
	cout << "ex)<let three=3;>\n";
}


void calculate()
{
	Token_stream ts;
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == help) print_help();
		else {
			if (t.kind == quit) return;
			ts.putback(t);
			cout << result << statement(ts) << endl;
		}
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		clean_up_mess(ts);
	}
}

int main()
try {

	st.declare("pi", 3.1415926535, false);	// these pre-defiend names are constants
	st.declare("e", 2.7182818284, false);
	st.declare("k", 1000, false);

	calculate();

	keep_window_open();

	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
