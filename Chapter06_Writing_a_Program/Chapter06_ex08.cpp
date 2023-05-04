#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h" // header provided by author // https://www.stroustrup.com/Programming/std_lib_facilities.h


using namespace std;


int main() {
    try {
        cout << "Bulls and Cows\n";
        while (true) {
            int n;
            cout << "Enter a number for a new game\n" <<
                "Enter 'q' if you want to stop the game\n";
            cin >> n;
            if (n == 'q' || n == 'Q') break;
            seed_randint(n);
            vector<char> game = {};
            int unique;
            int diff = 0;
            //97 - 122
            //0  25
            game.emplace_back(randint(25)+97);
            constexpr int gameSize = 4;
            while (game.size() < gameSize) {
                unique = randint(25)+97;
                for (int i = 0; i < game.size(); ++i)
                {
                    if (unique != game[i]) ++diff;
                    if (diff == game.size()) game.emplace_back(unique);
                }
                diff = 0;
            }
            char num = '?';
            int bullCount = 0, cowCount = 0;

            while (bullCount != game.size())
            {
                bullCount = 0;
                cowCount = 0;
                cout << "guess four different small letters\n";
                for (int i = 0; i < game.size(); ++i)
                {
                    cin >> num;
                    if (num < 97 || num>122) error("out of the range\n");
                    for (int j = 0; j < game.size(); ++j)
                    {
                        if (num == game[j] && i == j)
                        {
                            ++bullCount;
                        }
                        else if (num == game[j] && i != j)
                        {
                            ++cowCount;
                        }
                    }
                }
                cout << bullCount << " bull, " << cowCount << " cow\n";
                num = '?';
            }
            cout << "You got four bulls!!\n";
        }
        return 0;
    }
    catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Unknown exception!\n";
        return 2;
    }
}
