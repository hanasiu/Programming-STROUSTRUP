#include <iostream>

using namespace std;

template<typename ln, typename Pred>
ln find_if1(ln first, ln last, Pred pred) {
    while(first!=last && !pred(*first)) ++first;
    return first;
}

class Larger_than {
    int v;
    public:
    Larger_than(int vv): v(vv) { }
    bool operator()(int x) const { return x>v; }
};

int main() {
    vector<int> k = {1,2,3, 111, 211, 31, 2};
    auto i = find_if1(k.begin(), k.end(), Larger_than(100));
    cout << *i << endl;
}