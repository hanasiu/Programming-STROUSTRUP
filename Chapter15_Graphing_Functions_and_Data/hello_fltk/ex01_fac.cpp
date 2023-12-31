#include <iostream>
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int fac(int n)
{
    int r = 1;
    while (n > 1)
    {
        r *= n;
        --n;
    }
    return r;
}

int fac_recursive(int n)
{
    return n > 1 ? n * fac(n - 1) : 1;
}


class Fct : Shape {
    public:
    Fct(func, range1, range2, origin, c, x, y) { 
        funct(func), r1(range1), r2(range2), orig(origin), count(c), xscale(x), yscale(y)
    };    
    // Fct(double (*funct)(double), double r1, double r2, Point orig,
	// int count = 100, double xscale = 25, double yscale = 25);

    private:
    std::function<double (double)> funct;
    double r1;
    double r2;
    Point orig;
    int count;
    douuble xscale;
    double yscale;
};

int main() {
    std::cout << fac(5) << std::endl;
    std::cout << fac_recursive(5) << std::endl;
    return 0;
}