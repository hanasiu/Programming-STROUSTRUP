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
