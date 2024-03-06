
#include <iostream>
#include <stdexcept>
#include <string>
#include <chrono>
#include <vector>

struct Message {
    std::string content;
    std::string::size_type count;
    std::chrono::system_clock::time_point sent;
    Message(const std::string& s)
        : content{s}, count{s.size()},
        sent{std::chrono::system_clock::now()} { }
};

struct Node {
    const char* cs;
    int size;
    Node* next;
    Node* prev;
    Node(const std::string& s, Node* p = nullptr, Node* n = nullptr)
        : cs{s.c_str()}, size{int(s.size())}, prev{p}, next{n} { }
};

Message* get_input(std::istream& is)
{
    std::string buffer;
    std::getline(is, buffer);
    return new Message{buffer};
}

int main()
try {
    std::cout << "Message size: " << sizeof(Message) << '\n';   // 40
    std::cout << "Node size: " << sizeof(Node) << '\n';         // 32

    Node* nlist = new Node{"first node"};
    std::vector<Node*> vn;

 for (int i = 0; i < 7; ++i) {
    Message* p = get_input(std::cin);
    std::cout << "Message address: " << p << '\n';

    Node* n1 = new Node(p->content);
    std::cout << "Node n1 address: " << n1 << '\n';

    delete p; // Delete the Message object immediately after use

    Node* n2 = new Node("window pane");
    std::cout << "Node n2 address: " << n2 << '\n';

    vn.push_back(n1);
    vn.push_back(n2);
}

    for (auto n : vn) {
        std::cout << "Node address: " << n << '\n';
        delete n;
    }
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}