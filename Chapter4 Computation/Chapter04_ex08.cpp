#include <iostream>

using namespace std;

int main() {
   long long grains = 1;
   long long sum = 0;
   for (int squares = 1; squares <= 64; ++squares) {
      sum += grains;
      cout << "grains: " << grains << ", sum: " << sum << " squares: " << squares << endl;
      grains *= 2;
   }
   return 0;
}
