#include <iostream>

using namespace std;


// template<typename Ran>
// void sort_(Ran first, Ran last) {
//     sort(first, last);
// }

// template<typename Ran, typename Cmp>
// void sort_(Ran first, Ran last, Cmp cmp) {
//     sort(first, last, cmp);
// }
struct No_case {
    bool operator()(const string& x, const string& y) const 
    {
        for(int i = 0; i<x.length(); ++i) {
            if(i == y.length()) return false;
            char xx = tolower(x[i]);
            char yy = tolower(y[i]);
            if(xx<yy) return true;
            if(yy<xx) return false;
        }
        if(x.length()==y.length()) return false;
        return true;
    }
};

void sort_and_print(vector<string>& vc) {
    sort(vc.begin(), vc.end(), No_case());

    for(const auto& s : vc) 
    cout << s << '\n';
}

int main() {
    vector<string> i = {"kane", "son", "Dier", "moura"};
    sort_and_print(i);
    return 0;
}