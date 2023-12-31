#include <iostream>
#include <initializer_list>
#include <algorithm>

template<typename T>
class vector
{
    int sz;
    T *elem;
    int space;

public:
    vector() : sz{0}, elem{nullptr}, space{0} {}

    explicit vector(int s)
        : sz{s}, elem{new double[s]}, space{s}
    {
        for (int i = 0; i < sz; ++i)
        {
            elem[i] = 0;
        }
    }

    vector(const vector &);
    vector &operator=(const vector &);

    vector(vector &&);
    vector &operator=(vector &&);

    ~vector()
    {
        delete[] elem;
    }

    vector(std::initializer_list<T> lst)
        : sz{static_cast<int>(lst.size())}, elem{new T[sz]}
    {
        std::copy(lst.begin(), lst.end(), elem);
    }

    T &operator[](int n) { return elem[n]; }
    const T &operator[](int n) const { return elem[n]; }

    int size() const { return sz; }
    int capacity() const { return space; }

    T get(int n) const { return elem[n]; }
    void set(int n, T v) { elem[n] = v; }

    void reserve(int newalloc);
    void resize(int newsize);
    void push_back(T d);
};

vector::vector(const vector &arg)
    : sz{arg.sz}, elem{new T[arg.sz]}
{
    std::copy(arg.elem, arg.elem + sz, elem);
}

vector &vector::operator=(const vector &a)
{
    T *p = new T[a.sz];
    std::copy(a.elem, a.elem + sz, p);
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}

vector::vector(vector &&a)
    : sz{a.sz}, elem{a.elem}
{
    a.sz = 0;
    a.elem = nullptr;
}

vector &vector::operator=(const vector &a)
{
    if (this == &a)
        return *this;

    if (a.sz <= space)
    {
        for (int i = 0; i < a.sz; ++i)
            elem[i] = a.elem[i];
        sz = a.sz;
        return *this;

        T *p = new T[a.sz];
        for (int i = 0; i < a.sz; ++i)
            p[i] = a.elem[i];
        delete[] elem;
        space = sz = a.sz;
        elem = p;
        return *this;
    }
}

vector &vector::operator=(vector &&a)
{
    delete[] elem;
    elem = a.elem;
    sz = a.sz;
    a.elem = nullptr;
    a.sz = 0;
    return *this;
}

void vector::reserve(int newalloc)
{
    if (newalloc <= space)
        return;
    T *p = new T[newalloc];
    for (int i = 0; i < sz; ++i)
        p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = newalloc;
}

void vector::resize(int newsize)
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i)
        elem[i] = 0;
    sz = newsize;
}

void vector::push_back(T d)
{
    if (space == 0)
        reserve(8);
    else if (sz == space)
        reserve(2 * space);
    elem[sz] = d;
    ++sz;
}

void f()
{
    vector v(3);
    v.set(2, 2.2);
    vector v2 = v;
    v.set(1, 99);
    v2.set(0, 88);
    std::cout << v.get(0) << ' ' << v2.get(1) << std::endl;
}

void f2()
{
    vector v(3);
    v.set(2, 2.2);
    vector v2(4);
    v2 = v;
    std::cout << v2.get(2);
}

int main()
{
    // vector v(5);
    // for(int i = 0; i<v.size(); ++i) {
    //     v.set(i, 1.1 *i);
    //    //std::cout << "v[" << i << "]==" << v.get(i) << "\n";
    // }
    // f();
    // f2();

    vector v(10);
    T x = v[2];
    v[3] = x;
    // char lac[20];
    // lac[-2] = 'b';
    // v.resize(-77);

    return 0;
}

// clang++ --std=c++14 Vector.cpp && ./a.out && rm a.out