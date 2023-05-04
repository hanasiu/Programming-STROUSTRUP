#include "std_lib_facilities.h"

const int not_a_reading = -7777;
const int not_a_month = -1;

struct Day {
    vector<double> hour;
    Day();
};

Day::Day() :hour(24)
{
    for (int i = 0; i < hour.size(); ++i) hour[i] = not_a_reading;
}

struct Month {
    int month;
    vector<Day> day;
    Month()
        :month(not_a_month), day(32) { }
};

struct Year {
    int year;
    vector<Month> month;
    Year() :month(12) { }
};

struct Reading {
    int day;
    int hour;
    double temperature;
};

int month_to_int(string s);
bool is_valid(const Reading& r);
void end_of_loop(istream& ist, char term, const string& message);

istream& operator>>(istream& is, Reading& r)
{
    char ch1;
    if (is >> ch1 && ch1 != '(') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if (!is || ch2 != ')') error("bad reading");
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

istream& operator>>(istream& is, Month& m)
{
    char ch = 0;
    if (is >> ch && ch != '{') {
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    string month_marker;
    string mm;
    is >> month_marker >> mm;
    if (!is || month_marker != "month") error("bad start of month");
    m.month = month_to_int(mm);

    Reading r;
    int no_of_duplicate_readings = 0;
    int no_invalid_readings = 0;

    while (is >> r)
        if (is_valid(r)) {
            if (m.day[r.day].hour[r.hour] != not_a_reading)
                ++no_of_duplicate_readings;
            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else
            ++no_invalid_readings;
    end_of_loop(is, '}', "bad end of month");
    return is;
}

const int implausible_min = -200;
const int implausible_max = 200;

bool is_valid(const Reading& r)
{
    if (r.day < 1 || 31 < r.day) return false;
    if (r.hour < 0 || 23 < r.hour) return false;
    if (r.temperature < implausible_min || implausible_max < r.temperature)
        return false;
    return true;
}

istream& operator>>(istream& is, Year& y)
{
    char ch;
    is >> ch;
    if (ch != '{') {
        is.unget();
        is.clear(ios::failbit);
        return is;
    }

    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker != "year") error("bad start of year");
    y.year = yy;

    while (true) {
        Month m;
        if (!(is >> m)) break;
        y.month[m.month] = m;
    }

    end_of_loop(is, '}', "bad end of year");
    return is;
}

void end_of_loop(istream& ist, char term, const string& message)
{
    if (ist.fail()) {
        ist.clear();
        char ch;
        if (ist >> ch && ch == term) return;
        error(message);
    }
}

vector<string> month_input_tbl;    // month_input_tbl[0]=="jan"

void init_input_tbl(vector<string>& tbl)
{
    tbl.push_back("jan");
    tbl.push_back("feb");
    tbl.push_back("mar");
    tbl.push_back("apr");
    tbl.push_back("may");
    tbl.push_back("jun");
    tbl.push_back("jul");
    tbl.push_back("aug");
    tbl.push_back("sep");
    tbl.push_back("oct");
    tbl.push_back("nov");
    tbl.push_back("dec");
}

int month_to_int(string s)
{
    for (int i = 0; i < 12; ++i) if (month_input_tbl[i] == s) return i;
    return -1;
}

vector<string> month_print_tbl;    

void init_print_tbl(vector<string>& tbl)
{
    tbl.push_back("January");
    tbl.push_back("February");
    tbl.push_back("March");
    tbl.push_back("April");
    tbl.push_back("May");
    tbl.push_back("June");
    tbl.push_back("July");
    tbl.push_back("August");
    tbl.push_back("September");
    tbl.push_back("October");
    tbl.push_back("November");
    tbl.push_back("December");
}

string int_to_month(int i)
{
    if (i < 0 || 12 <= i) error("bad month index");
    return month_print_tbl[i];
}

void print_day(ostream& ost, const Day& d, int daynum)
{
    bool is_empty = true;
    for (int i = 0; i < 24; ++i) {
        if (d.hour[i] != not_a_reading) {
            is_empty = false;
            break;
        }
    }
    if (is_empty) return;  
    ost << "\n        " << daynum;
    for (int i = 0; i < 24; ++i) {
        if (d.hour[i] != not_a_reading)
            ost << "\n            " << i << ":00 - " << d.hour[i] << " F";
    }
}

void print_month(ostream& ost, const Month& m)
{
    if (m.month == not_a_month) return;
    ost << "\n    " << int_to_month(m.month);
    for (int i = 1; i < 32; ++i)
        print_day(ost, m.day[i], i);
}

void print_year(ostream& ost, const Year& y)
{
    ost << y.year << ' ';
    for (int i = 0; i < 12; ++i)
        print_month(ost, y.month[i]);
}


int main()
try
{
    init_print_tbl(month_print_tbl);
    init_input_tbl(month_input_tbl);


    cout << "Please enter input file name\n";
    string name;
    cin >> name;
    ifstream ifs(name.c_str());
    if (!ifs) error("can't open input file", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);   


    cout << "Please enter output file name\n";
    cin >> name;
    ofstream ofs(name.c_str());
    if (!ofs) error("can't open output file", name);

 
    vector<Year> ys;
    while (true) {
        Year y;       
        if (!(ifs >> y)) break;
        ys.push_back(y);
    }
    cout << "read " << ys.size() << " years of readings\n";

    for (int i = 0; i < ys.size(); ++i) {
        print_year(ofs, ys[i]);
        ofs << endl;
    }
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n";
    return 2;
}
