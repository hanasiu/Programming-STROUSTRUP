#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string name = "";
    int score = 0;
    vector<string> names = {};
    vector<int> scores = {};
    while(cin >> name >> score)
    {
        for(auto i : names)
        {
            if(name == i)
            {
                cin.clear();
                cout << "error!!!!!! a name is entered twice." << endl;
                return 0;
            }
        }
        names.emplace_back(name);
        scores.emplace_back(score);
        cin.clear();
    }
    for(int i = 0; i<names.size(); ++i)
    {
        cout << "name: " << names[i] 
        << ", score: " << scores[i] << endl;
    }

    return 0;
}
