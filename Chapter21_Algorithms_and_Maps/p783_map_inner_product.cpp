#include <iostream>
#include <map>

using namespace std;

template<typename ln, typename ln2, typename T, typename BinOp, typename BinOp2> 
T inner_product(ln first, ln last, ln2 first2, T init, BinOp op, BinOp2 op2)
{
    while(first!=last) {
        init = op(init, op2(*first, *first2));
        ++first;
        ++first2;
    }
    return init;
}

double weighted_value(
    const pair<string,double>& a, 
    const pair<string, double>& b
) {
    return a.second*b.second;
}

int main()
{
    map<string, double> dow_price = {
        {"MMM", 81.86}, {"AA", 34.69}, {"MO", 54.45}
    };

        map<string, double> dow_weight = {
        {"MMM", 4}, {"AA", 7}, {"MO", 11}
    };

    double dji_index = inner_product(dow_price.begin(), dow_price.end(),
    dow_weight.begin(), 0.0, plus<double>(), weighted_value);

    cout << dji_index << endl;
}