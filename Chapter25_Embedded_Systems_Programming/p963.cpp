#include <iostream>

using namespace std;

void infinite() {
    unsigned char max = 160;
    for(signed char i = 0; i<max; ++i) cout << int(i) << endl;
}
void infinite1() {
    int i = 0;
    while(++i) cout << i << " ";
}

void p965() {
    int si =128;
    char c = si;
    unsigned char uc = si;
    signed char sc = si;
    cout << si << endl;
    cout << int(c) << endl;
    cout << int(uc) << endl;
    cout << int(sc) << endl;
}

int main() {
    p965();
    unsigned int a = -3;
    cout << a << endl;
}