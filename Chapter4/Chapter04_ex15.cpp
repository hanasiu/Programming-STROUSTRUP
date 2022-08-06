#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num){
    if(num<=1) return false;
    for (int p=2; p*p<=num; p++)
    {
        for (int i=p*p; i<=num; i += p)
            if(num==i)
            {
                return false;
            }
    }
    return true;
}
 
 
 
int main()
{
    int number = 2;
    int count = 1;
    int howMany = 0;
    vector <int> primeList = {};
    cin>>howMany;
    while(primeList.size()<howMany)
    {
        if(isPrime(number))
        {
            primeList.emplace_back(number);
        }
        ++number;
    }
    for(auto i : primeList)
    {
        cout << i << " ";
    }
    return 0;
}
