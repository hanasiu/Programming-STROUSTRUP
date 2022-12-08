#include "std_lib_facilities.h"

struct Reading {
    int hour;
    double temperature;
    Reading(int h, double t) : hour(h), temperature(t) { }
};

ostream& operator<<(ostream& os, const Reading& r)
{
    return os << r.hour << ' ' << r.temperature;
}

const int max_temp = 107;
const int min_temp = -43;

Reading create_reading()
{
    int h = randint(0, 24);
    double t = randint(min_temp, max_temp) + randint(-10, 10) / double(10);
    return Reading(h, t);
}

void write_to_file(const vector<Reading>& r, const string& name)
{
    ofstream ost(name.c_str());
    if (!ost) error("can't open output file ", name);
    for (int i = 0; i < r.size(); ++i)
        ost << r[i] << endl;
}

int main() 
try {
    vector<Reading> readings;
    for (int i = 0; i < 250; ++i)
        readings.emplace_back(create_reading());

    write_to_file(readings, "raw_temps.txt");
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
