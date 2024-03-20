#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;

int binary_search(vector<int> i, int target) {
    sort(i.begin(), i.end());
    int start = 0;
    int end = i.size() - 1;
    int middleIndex = (end + start) / 2;
    while(start<=end) {
        int middleIndex = (end + start) / 2;
        cout << start << " " << end << endl;
        if(middleIndex < 0 || middleIndex > i.size() - 1) {
            break;
        }
        if(i[middleIndex] == target) {
            return middleIndex;
        } else
        if(i[middleIndex] > target) {
            end = middleIndex - 1;
            continue;
        } else 
        if(i[middleIndex] < target) {
            start = middleIndex + 1;
            continue;
        }

    }
    return 999999;
}

int main() {

   // vector<int> example = {0,0,0,0,77};
  //  int result = binary_search(example, 77);
    vector<int> v {1,2,3,5,8,13,21};
    for(int x : {1,5,8,21,-7,2,44}) {
        if(binary_search(v, x) == false) cout << x << " failed";
    }
    return 0;
}