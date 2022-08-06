#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main()
{
    int num;
    vector<int> seq = {}; 
    vector<int> modeList = {};
    cout << "enter numbers. If you want to stop, enter 'q'" << endl;
    while(cin>>num&&num!='q')
    {
        seq.emplace_back(num);
    }
    sort(seq.begin(), seq.end());
    int count = 1;
    int maxcount = 1;
    int mode = seq[0];
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
    for(auto i : modeList)
    {
        cout << i << " ";
    }
    
    return 0;
}
