/*
This is the integer version!
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
	integer-literal
Input comes from cin through the Token_stream called ts.
*/


#include "chapter10_ex06.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
const char name = 'a';
const char let = 'L';
const string declkey = "let";
const string prompt = "> ";
const string result = "= ";




class Token {
public:
	char kind;
	Roman_int value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, Roman_int val) :kind(ch), value(val) { }
	Token(char ch, string n) : kind(ch), name(n) { }
};

class Token_stream {

public:
	Token_stream() :full(false), buffer(0) { }
	Token get();
	void putback(Token t);
	void ignore(char c);
private:
	bool full;
	Token buffer;
};

void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;
	full = true;
}


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
		//case '.':
	/*case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		int val;
		cin >> val;
		return Token(number, val);
	}*/
	case N: case I: case V: case X:
	case L: case C: case D: case M: // Roman numeral
	{
		cin.putback(ch);
		Roman_int r;
		cin >> r;
		return Token(number, r);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
			cin.putback(ch);
			if (s == declkey) return Token(let); // keyword "let"
			return Token(name, s);
		}
		error("Bad token");
	}
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

Token_stream ts;


struct Variable {
	string name;
	Roman_int value;
	Variable(string n, Roman_int r, bool va = true) :name(n), value(r) { }
};


vector<Variable> var_table;

Roman_int get_value(string s)
// return the value of the Variable names s
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined variable ", s);
}

//------------------------------------------------------------------------------

void set_value(string s, Roman_int d)
// set the Variable named s to d
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) {
			var_table[i].value = d;
			return;
		}
	error("set: undefined variable ", s);
}

//------------------------------------------------------------------------------

bool is_declared(string var)
// is var already in var_table?
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == var) return true;
	return false;
}

//------------------------------------------------------------------------------

Roman_int define_name(string var, Roman_int val)
// add (var,val) to var_table
{
	if (is_declared(var)) error(var, " declared twice");
	var_table.push_back(Variable(var, val));
	return val;
}

//------------------------------------------------------------------------------

Roman_int expression(); // declaration so that primary() can call expression()

// deal with numbers and parentheses
Roman_int primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':           // handle '(' expression ')'
	{   Roman_int d = expression();
	t = ts.get();
	if (t.kind != ')') error("')' expected");
	return d;
	}
	case number:
		return t.value;    // return the number's value
	case name:
		return get_value(t.name); // return the variable's value
	case '-':
		return -primary();
	case '+':
		return primary();
	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

// deal with *, /, and %
Roman_int term()
{
	Roman_int left = primary();
	Token t = ts.get(); // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left = left * primary();
			t = ts.get();
			break;
		case '/':
		{   Roman_int d = primary();
		if (d == Roman_int(0)) error("divide by zero");
		left = left / d;
		t = ts.get();
		break;
		}
		case '%':
		{   Roman_int i1 = left;
		Roman_int i2 = term();
		if (i2 == Roman_int(0)) error("%: divide by zero");
		left = i1 % i2;
		t = ts.get();
		break;
		}
		default:
			ts.putback(t);        // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with + and -
Roman_int expression()
{
	Roman_int left = term();    // read and evaluate a Term
	Token t = ts.get();         // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left = left + term();     // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left = left - term();     // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);      // put t back into the token stream
			return left;        // finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------

Roman_int declaration()
// handle: name = expression
// declare a variable called "name" with the initial value "expression"
{
	Token t = ts.get();
	if (t.kind != name) error("name expected in declaration");
	string var_name = t.name;

	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", var_name);

	Roman_int d = expression();
	define_name(var_name, d);
	return d;
}

//------------------------------------------------------------------------------

Roman_int statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.putback(t);
		return expression();
	}
}

//------------------------------------------------------------------------------

void clean_up_mess()
{
	ts.ignore(print);
}

//------------------------------------------------------------------------------

void calculate()
{
	while (cin)
		try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();    // first discard all "prints"
		if (t.kind == quit) return;        // quit
		ts.putback(t);
		cout << result << statement() << endl;
	}
	catch (exception& e) {
		cerr << e.what() << endl;        // write error message
		clean_up_mess();
	}
}

//------------------------------------------------------------------------------

int main()
try {
	// predefine names:
	//define_name("pi",3.1415926535);
	//define_name("e",2.7182818284);

	calculate();

	keep_window_open();    // cope with Windows console mode
	return 0;
}
catch (exception& e) {
	cerr << e.what() << endl;
	keep_window_open("~~");
	return 1;
}
catch (...) {
	cerr << "exception \n";
	keep_window_open("~~");
	return 2;
}
