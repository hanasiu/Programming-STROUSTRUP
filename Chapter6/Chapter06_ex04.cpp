#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "std_lib_facilities.h"

using namespace std;

class Name_value {
public:
    string name;
    int score;
    Name_value(string str, int val)
        :name(str), score(val) { }
};

int main()
{
    string name = "";
    int score = 0;
    vector<Name_value> nameScore = {};
    while (cin >> name >> score && name != "q")
    {
        for(int i = 0; i<nameScore.size(); ++i)
        {
            if (name == nameScore[i].name)
            {
                cin.clear();
                cout << "error!!!!!! a name is entered twice." << endl;
                return 0;
            }
        }
        nameScore.emplace_back(Name_value(name, score));
        cin.clear();
    }
    for (int i = 0; i < nameScore.size(); ++i)
    {
        cout << "name: " << nameScore[i].name
            << ", score: " << nameScore[i].score << endl;
    }

    return 0;
}
