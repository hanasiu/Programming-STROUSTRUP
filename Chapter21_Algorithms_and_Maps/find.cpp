#include <iostream>

using namespace std;

template<typename ln, typename T>
ln find1(ln first, ln last, const T& val) {
    while(first!=last && *first!=val) ++first;
    return first;
}

template<typename ln, typename T>
ln find2(ln first, ln last, const T& val) {
    for(ln p = first; p!=last; ++p) {
        if(*p==val) return p;
    }
    return last;
}

int main() {
    vector<int> i = { 1, 4, 5, 2, 100, 201, 300, 2};
    auto k = find1(i.begin(), i.end(), 201);
    auto n = find2(i.begin(), i.end(), 201);
    cout << *k << endl << *n << endl;
    return 0;
}