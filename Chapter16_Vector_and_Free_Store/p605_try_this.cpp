#include <iostream>

class Parent {
public:
    Parent() {
        std::cout << "Parent constructor called" << std::endl;
    }

    virtual ~Parent() {
        std::cout << "Parent destructor called" << std::endl;
    }
};

class Child : public Parent {
public:
    Child() {
        std::cout << "Child constructor called" << std::endl;
    }

    ~Child() {
        std::cout << "Child destructor called" << std::endl;
    }
};

int main() {
    std::cout << "Creating a Parent object:" << std::endl;
    Parent parentObj;

    std::cout << "\nCreating a Child object:" << std::endl;
    Child childObj;

    std::cout << "\nCreating a Parent pointer to a Child object:" << std::endl;
    Parent* parentPtrToChild = new Child;

    std::cout << "\nDeleting the Parent pointer to a Child object:" << std::endl;
    delete parentPtrToChild;

    std::cout << "\nExiting the program:" << std::endl;

    return 0;
}

