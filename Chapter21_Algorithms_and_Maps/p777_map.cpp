#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> words;
    for (string s; cin >> s;)
    {
        if (s == "stop")
        {
            break;
        }
        ++words[s];
    }
    for (const auto &p : words)
    {
        cout << p.first << ": " << p.second << "\n";
    }
    return 0;
}