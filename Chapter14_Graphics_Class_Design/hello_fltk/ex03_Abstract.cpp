#include <iostream>

using namespace std;

class Form {
   protected:
    float dimension;

   public:
    void getDimension() {
        cin >> dimension;
    }

    // pure virtual Function
    virtual float calculateArea() = 0;
};

int main() {
    Form k;
    //error message:
    //object of abstract class type "Form" is not allowed:
}