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
    cout << "enter a name and a score in order. enter '*' if you want to stop" << endl;
    while(cin >> name && name != "*" && cin >> score )
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
    string search = "";
    bool notFound = true; 
    cout << "enter a name. enter '*' if you want to stop" << endl;
    while(cin>>search&&search!="*"){
    notFound = true;
    for(int i = 0; i<names.size(); ++i)
    {
        if(names[i]==search)
        {
            cout << "name: " << names[i] 
            << ", score: " << scores[i] << endl;
            notFound = false;
        }
    }
    if(notFound)
    {
        cout << "name not found" << endl;
    }
    }

    return 0;
}
