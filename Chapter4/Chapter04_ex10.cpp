#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

int main() {
   std::random_device dev;
   std::mt19937 rng(dev());
   std::uniform_int_distribution < std::mt19937::result_type > dist6(0, 2);
   //https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c

   char player;

   vector < char > comRPS = {
      'r',
      'p',
      's'
   };
   int myScore = 0, comScore = 0, draw = 0;
   int coin = 10;
   char answer = 'n';
   while (true) {
      cin >> player;
      switch (comRPS[dist6(rng)]) {
      case 'r':
         switch (player) {
         case 'r':
            cout << "Tie!" << endl;
            ++draw;
            break;
         case 'p':
            cout << "You win!" << endl;
            ++myScore;
            break;
         case 's':
            cout << "You lose!" << endl;
            ++comScore;
            break;
         }
         break;
      case 'p':
         switch (player) {
         case 'r':
            cout << "You lose!" << endl;
            ++comScore;
            break;
         case 'p':
            cout << "Tie!" << endl;
            ++draw;
            break;
         case 's':
            cout << "You win!" << endl;
            ++myScore;
            break;
         }
         break;
      case 's':
         switch (player) {
         case 'r':
            cout << "You win!" << endl;
            ++myScore;
            break;
         case 'p':
            cout << "You lose!" << endl;
            ++comScore;
            break;
         case 's':
            cout << "Draw!" << endl;
            ++draw;
            break;
         }
         break;
      }
      --coin;
      if (coin == 0) {
         cout << "Do you want more? enter y or n" << endl;
         cin >> answer;
         if (answer == 'y') {
            coin += 10;
         } else break;
      }
   }
   cout << "My Score: " << myScore << ", Computer's Score: " << comScore << ", Draw: " << draw << endl;

   return 0;
}
