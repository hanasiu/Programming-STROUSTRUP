//This includes exercise 13.
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
            vector<int> game = {};
            int unique;
            int diff = 0;
            game.emplace_back(randint(9));
            while(game.size()<4) {
                unique = randint(9);
                for (int i = 0; i < game.size(); ++i)
                {
                    if (unique != game[i]) ++diff;
                    if (diff == game.size()) game.emplace_back(unique);
                }
                diff = 0;
            }
            int num = '?';
            int bullCount = 0, cowCount = 0;

            while (bullCount != 4)
            {
                bullCount = 0;
                cowCount = 0;
                cout << "guess four different integers in the range 0 to 9\n";
                for (int i = 0; i < 4; ++i)
                {
                    cin >> num;
                    if (num < 0 || num>9) error("out of the range: 0 to 9\n");
                    for (int j = 0; j < 4; ++j)
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
