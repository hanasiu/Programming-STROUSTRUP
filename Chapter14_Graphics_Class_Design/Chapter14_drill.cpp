#include <iostream>

using namespace std;

class B1 {
    public:
    virtual void vf() const { cout << "B1::vf "; }
    void f() const { cout << "B1::f ";  }
    virtual void pvf() =0;
};

class D1 : public B1 {
    public:
    void vf() const override { cout << "D1::vf "; }
    //void f() const { cout << "D1:v "; }
    void pvf() override { cout << "D1::pvf "; }
};

class D2 : public D1 {
    public:
    void vf() const override { cout << "D2::vf "; }
    void pvf() override { cout << "D2::pvf "; }
};

class B2 {
    public:
    virtual void pvf() =0;
};

class D21 : public B2 {
    public:
    string stringD;
    void pvf() override { cout << stringD; }
};

class D22 : public B2 {
    public:
    int intD;
    void pvf() override { cout << intD; }
};

void f(B2& b) {
    b.pvf();
}


// void call(const B1& b) {
//     b.f();
//     b.vf();
//     //b.pvf();
// }

int main() {
    //B1 example;
    //call(example);
    //cout << endl;
    D1 example2;
    example2.f();
    example2.vf();
    example2.pvf();
    // B1& example3 = example2;
    // cout << endl;
    // call(example3);
    cout << endl;
    D2 example4;
    example4.f();
    example4.vf();
    example4.pvf();
    cout << endl;

    D21 example5;
    example5.stringD = "babo";
    D22 example6;
    example6.intD = 123;
    f(example5);
    cout << endl;
    f(example6);
    return 0;
}