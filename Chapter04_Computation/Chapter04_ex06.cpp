#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
   vector <string> numList = {
      "zero",
      "one",
      "two",
      "three",
      "four",
      "five",
      "six",
      "seven",
      "eight",
      "nine"
   };
   int num = 0;
   string numString = "";
   while (cin >> num >> numString) {
      cout << numList[num] << endl;
      for (int i = 0; i < numList.size(); ++i) {
         if (numList[i] == numString) {
            cout << i << endl;
         }
      }
   }

   return 0;
}
