#include <iostream>

using namespace std;

int main() {
    for(unsigned i; cin>>i;) {
        cout << dec << i << "=="
        <<hex << "0x" << i << "=="
        <<bitset<8*sizeof(unsigned)>{i} << endl;
    }

    cout << bitset<8>{'c'};
}