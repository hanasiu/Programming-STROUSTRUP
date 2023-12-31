#include <iostream>

int main() {
    int* p = new int{77};
    int* q = p;
    *p = 88;
    std::cout << *q << std::endl;

    int* p1 = new int{77};
    int* q1 = new int{*p1};
    *p1 = 88;
    std::cout << *q1 << std::endl;

    return 0;
} 

//clang++ --std=c++14 p637.cpp && ./a.out && rm a.out