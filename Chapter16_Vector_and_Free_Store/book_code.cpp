#include <iostream>

void sizes(char ch, int i, int *p, bool b, double d, std::vector<int> k)
{
    std::cout << "char " << sizeof(char) << " " << sizeof(ch) << std::endl
              << "int " << sizeof(int) << " " << sizeof(i) << std::endl
              << "int* " << sizeof(int *) << " " << sizeof(p) << std::endl
              << "bool " << sizeof(bool) << " " << sizeof(b) << std::endl
              << "double " << sizeof(double) << " " << sizeof(d) << std::endl
              << "vector int " << sizeof(k) << std::endl;
}

int main()
{
    int x = 17;
    int *pi = &x;

    double e = 2.81828;
    double *pd = &e;

    std::cout << "pi==" << pi << "; contents of pi==" << *pi << "\n";
    std::cout << "pd==" << pd << "; contents of pd==" << *pd << "\n";
    int y = 3;
    double *array = new double[y];
    std::cout << "page 590" << std::endl;
    char ch;
    int i;
    int *p;
    bool b;
    double d;
    std::vector<int> k(1000);
    sizes(ch, i, p, b, d, k);
    return 0;
}

// clang++ --std=c++14 book_code.cpp && ./a.out && rm ./a.out