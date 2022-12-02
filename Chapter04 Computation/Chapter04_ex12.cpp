#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num){
    vector<int> primeList = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for(int i = 0; i<primeList.size(); ++i)
    {
        if(num!=primeList[i]&&num%primeList[i]==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int max = 0;
    int number = 2;
    while(cin>>max)
    {
        while(number<=max)
        {
            if(isPrime(number))
            {
                cout << number << " ";
            }
            ++number;
        }
        cout << endl;
        number = 2;
    }
    return 0;
}
