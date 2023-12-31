#include <string>
#include <iostream>

class Link
{
public:
    std::string value;

    Link(const std::string &v, Link *p = nullptr, Link *s = nullptr)
        : value{v}, prev{p}, succ{s} {}

    Link *insert(Link *n);
    Link *add(Link *n);
    Link *erase();
    Link *find(const std::string &s);
    const Link *find(const std::string &s) const;

    Link *advance(int n) const;

    Link *next() const { return succ; }
    Link *previous() const { return prev; }

private:
    Link *prev;
    Link *succ;
};

Link *add(Link *p, Link *n)
{
}

Link *Link::erase()
{
    if (this == nullptr)
        return nullptr;
    if (succ)
        succ->prev = prev;
    if (prev)
        prev->succ = succ;
    return succ;
}

Link *Link::find(const std::string &s)
{
    Link *t = this;
    while (t)
    {
        if (t->value == s)
            return t;
        t = t->succ;
    }
    return nullptr;
}

Link *Link::insert(Link *n)
{
    if (n == nullptr)
        return nullptr;
    if (this == nullptr)
        return n;
    n->succ = this;
    if (prev)
        prev->succ = n;
    n->prev = prev;
    prev = n;
    return n;
}

void print_all(Link *p)
{
    std::cout << "{ ";
    while (p)
    {
        std::cout << p->value;
        if (p = p->next())
            std::cout << ", ";
    }
    std::cout << " }";
}

int main()
{
    Link *norse_gods = new Link{"Thor"};
    norse_gods = norse_gods->insert(new Link{"Odin"});
    norse_gods = norse_gods->insert(new Link{"Zeus"});
    norse_gods = norse_gods->insert(new Link{"Freia"});

    Link *greek_gods = new Link{"Hera"};
    greek_gods = greek_gods->insert(new Link{"Athena"});
    greek_gods = greek_gods->insert(new Link{"Mars"});
    greek_gods = greek_gods->insert(new Link{"Poseidon"});

    Link *p = greek_gods->find("Mars");
    if (p)
        p->value = "Ares";

    Link *p2 = norse_gods->find("Zeus");
    if (p2)
    {
        if (p2 == norse_gods)
            norse_gods = p2->next();
        p2->erase();
        greek_gods = greek_gods->insert(p2);
    }

    print_all(norse_gods);
    std::cout << "\n";
    print_all(greek_gods);
    std::cout << "\n";

    return 0;
}
