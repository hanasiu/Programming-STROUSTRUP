#include <iostream>

using namespace std;

int main()
{
    int num = 50;
    int diff = 50;
    int user = 0;
    cin >> user;
    int count = 0;
    while(1)
    {
        ++count;
        if(num==user)
        {
            cout << "the number is " << num << endl
            << "how many guesses: " << count << endl;
            break;
        }
        if(num<user)
        {
            cout << "Is the number you are thinking of larger than " << num << "?\n";
            diff>=1?num+=diff:num+=1;
            diff/=2;
        } else 
        {
            cout << "Is the number you are thinking of less than " << num << "?\n";
            diff>=1?num-=diff:num-=1;
            diff/=2;
        }
    }
    return 0;
}
