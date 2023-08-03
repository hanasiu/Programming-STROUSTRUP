//#include "Simple_window.h"
//#include "Graph.h"
#include <iostream>
#include <list>
#include "std_lib_facilities.h"

using namespace std;

class Iterator
{
public:
    virtual double *next() = 0;

protected:
    int pointer;
};

class Vector_iterator : public Iterator
{
public:
    Vector_iterator(const vector<double>& vv) : v(vv)
    {
        pointer = 0;
    }

    double* next();
private:
    vector<double> v;
};

double* Vector_iterator::next() {
    if (v.size() && v.size() > pointer) {
        ++pointer;
        return &v[pointer-1];
    }
    else return 0;
}

class List_iterator : public Iterator {
public:
    List_iterator(const list<double>& vv) : v(vv) {
        pointer = v.begin();
    }

    double* next();
private:
    list<double> v;
    list<double>::iterator pointer;
};

double* List_iterator::next() {
    double* p;

    if (v.size() && v.size() > distance(v.begin(),pointer)) {
        p = &*pointer;
        pointer++;
        return p;
    }
    else return 0;
}

void print(Iterator& it) {
    double* p;
    p = it.next();
    while (p != 0) {
        cout << *p << endl;
        p = it.next();
    }
}

int main()
try {
    vector<double> vec;
    for (int i = 0; i<10; ++i)
        vec.push_back(i);

    Vector_iterator vi(vec);
    print(vi);

    list<double> l;

    l.push_back(1.9);
    l.push_back(2.9);
    l.push_back(3.9);

    List_iterator li(l);
    print(li);

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}
