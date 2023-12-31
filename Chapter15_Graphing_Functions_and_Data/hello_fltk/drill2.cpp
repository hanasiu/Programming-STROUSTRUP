#include <string>
#include <iostream>
#include <exception>

struct Person
{
public:
    Person(std::string n = "", std::string n2 = "", int a = 0) : first_name(n), second_name(n2), age(a)
    {
        if (a < 0 || a > 150)
        {
            throw std::invalid_argument("invalid age");
        }
        if (n.find_first_of(";:\"'[]*&^%$#@!") != std::string::npos)
        {
            throw std::invalid_argument("invalid name");
        }
                if (n2.find_first_of(";:\"'[]*&^%$#@!") != std::string::npos)
        {
            throw std::invalid_argument("invalid name");
        }
    }

    std::string get_name() { return first_name + " " + second_name; }
    int get_age() { return age; }

    friend std::istream &operator>>(std::istream &in, Person &p);

private:
    std::string first_name;
    std::string second_name;
    int age;
};

std::istream &operator>>(std::istream &in, Person &p)
{
    std::cout << "enter a first name" << std::endl;
    in >> p.first_name;
    if (p.first_name.find_first_of(";:\"'[]*&^%$#@!") != std::string::npos)
    {
        throw std::invalid_argument("invalid name");
    }
        std::cout << "enter a second name" << std::endl;
    in >> p.second_name;
    if (p.second_name.find_first_of(";:\"'[]*&^%$#@!") != std::string::npos)
    {
        throw std::invalid_argument("invalid name");
    }
    std::cout << "enter an age" << std::endl;
    in >> p.age;
    if (p.age < 0 || p.age > 150)
    {
        throw std::invalid_argument("invalid age");
    }
    return in;
}
int main()
{
    try
    {
        std::vector<Person> list;
        while(std::cin) {
            Person k;
            std::cin >> k;
            list.emplace_back(k);
            if(k.get_name().substr(0, 4) == "stop") {
                break;
            }
        }
        for(auto p : list) {
        std::cout << p.get_name() << " " << p.get_age() << std::endl;
        }

    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}