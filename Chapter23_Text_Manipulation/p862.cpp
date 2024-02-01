#include <map>
#include <fstream>
#include <iostream>

using namespace std;

typedef vector<string>::const_iterator Line_iter;

class Message{
    Line_iter first;
    Line_iter last;
    public:
    Message(Line_iter p1, Line_iter p2): first{p1}, last{p2} { }
    Line_iter begin() const { return first;}
    Line_iter end() const { return last; }
};

using Mess_iter = vector<Message>::const_iterator;

struct Mail_file {
    string name;
    vector<string> lines;
    vector<Message> m;

    Mail_file(const string& n);

    Mess_iter begin() const { return m.begin(); }
    Mess_iter end() const { return m.end(); }
};

bool find_from_addr(const Message* m, string& s);
string find_subjet(const Message* m);

Mail_file::Mail_file(const string& n) {
    ifstream in {n};
    if(!in) {
        cerr << "no " << n << '\n';
        exit(1);
    }

    for(string s; getline(in,s);)
    lines.push_back(s);

    auto first = lines.begin();
    for(auto p = lines.begin(); p!=lines.end(); ++p) {
        if(*p == "----") {
            m.push_back(Message(first, p));
            first = p+1;
        }
    }
}

int is_prefix(const string& s, const string& p) {
    int n = p.size();
    if(string(s,0,n)==p) return n;
    return 0;
}

bool find_from_addr(const Message* m, string& s) {
    for(const auto& x : *m) 
    if(int n = is_prefix(x, "From: ")) {
        s = string(x, n);
        return true;
    }
    return false;
}

string find_subject(const Message* m) {
    for(const auto& x : *m) 
    if(int n = is_prefix(x, "Subject: ")) return string(x,n);
    return "";
}

int main() {
    Mail_file mfile("my-mail-file.txt");

    multimap<string, const Message*> sender;

    for(const auto& m : mfile) {
        string s;
        if(find_from_addr(&m, s))
        sender.insert(make_pair(s, &m));
    }

    auto pp = sender.equal_range("John Doe <jdoe@machine.example>");
    for(auto p = pp.first; p!=pp.second; ++p)
    cout << find_subject(p->second) << '\n';

}