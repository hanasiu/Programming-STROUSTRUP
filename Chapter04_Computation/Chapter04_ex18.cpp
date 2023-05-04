#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
    cout << "ax^2+bx+c=0" << endl 
    << "enter a, b, c. then I'll give you x." << endl;
    double a = 0, b = 0, c =0, x1=0, x2=0;
    while(cin>>a>>b>>c)
    {
        x1=(-1*b+sqrt(b*b-4*a*c))/2*a;
        x2=(-1*b-sqrt(b*b-4*a*c))/2*a;
        cout << "x1: " << x1 << endl
        << "x2: " << x2 << endl;
    }

    return 0;
}
