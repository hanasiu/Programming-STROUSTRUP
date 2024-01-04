#include <iostream>

using namespace std;

template <typename ln, typename T>
T accumulate(ln first, ln last, T init)
{
    while (first != last)
    {
        init = init + *first;
        ++first;
    }
    return init;
}

template <typename ln, typename T, typename BinOp>
T accumulate(ln first, ln last, T init, BinOp op)
{
    while (first != last)
    {
        init = op(init, *first);
        ++first;
    }
    return init;
}

struct Record
{
    double unit_price;
    int units;
};

double price(double v, const Record &r)
{
    return v + r.unit_price * r.units;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    cout << accumulate(a, a + sizeof(a) / sizeof(int), 0) << endl;
    Record b, c, d, e, f;
    b.unit_price = 50;
    b.units = 5;
    c.unit_price = 60;
    c.units = 7;
    d.unit_price = 80;
    d.units = 9;
    e.unit_price = 90;
    e.units = 10;
    f.unit_price = 110;
    f.units = 11;
    vector<Record> container = {b,c,d,e,f};
    double result = 0.0;
    cout << accumulate(container.begin(), container.end(), result, price) << endl;
}