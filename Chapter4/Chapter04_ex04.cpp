#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num = 50;
    int diff = 25;
    string answer;
    cout << "answer: large, small, yes" << endl
        << "Is the number you are thinking of larger than 50?\n";
    while (cin >> answer)
    {
        if (answer == "large")
        {
            num += diff;
            cout << "the number is " << num << "?\n";
            diff % 2 == 0 ? diff /= 2 : diff = diff / 2 + 1;
        }
        else if(answer == "small")
        {
            num -= diff;
            cout << "the number is " << num << "?\n";
            diff % 2 == 0 ? diff /= 2 : diff = diff / 2 + 1;
        }
        else if (answer == "yes")
        {
            cout << "the number is " << num << "?\n";
            break;
        }
    }
    return 0;
}
