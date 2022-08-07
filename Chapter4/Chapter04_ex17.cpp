#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    string str;
    vector<string> seq = {}; 
    vector<string> modeList = {};
    cout << "enter strings. If you want to stop, enter 'q'" << endl;
    while(cin>>str&&str!="q")
    {
        seq.emplace_back(str);
    }
    sort(seq.begin(), seq.end());
    int count = 1;
    int maxcount = 1;
    string mode = seq[0];
    for(int i = 0; i<seq.size()-1; ++i)
    {
        if(seq[i]==seq[i+1])
        {
            ++count;
        } else if(count>maxcount)
        {
            maxcount=count;
            modeList.erase(modeList.begin(), modeList.end());
            modeList.emplace_back(seq[i]);
            count = 1;
        } else if(count == maxcount)
        {
            modeList.emplace_back(seq[i]);
            count = 1;
        }
        
    }
    
    if(count>maxcount)
        {
            maxcount=count;
            modeList.erase(modeList.begin(), modeList.end());
            modeList.emplace_back(seq[seq.size()-1]);
        } else if(count == maxcount)
        {
            modeList.emplace_back(seq[seq.size()-1]);
        }
    cout << "min: " << seq[0] << endl
         << "max: " << seq[seq.size()-1] << endl
         << "mode : " << maxcount << endl
    << "mode list: ";
    for(auto i : modeList)
    {
        cout << i << " ";
    }
    
    return 0;
}
