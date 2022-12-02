#include <iostream>
#include <vector>
#include <string>

using namespace std;

double getNum() {
   cout << "Enter single-digit numbers as either as digits or spelled out.\n";
   double num = 0;
   if (cin >> num) {
      return num;
   }
   cin.clear();
   string numString = "";
   cin >> numString;
   vector < string > numList = {
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

   for (int i = 0; i < numList.size(); ++i) {
      if (numList[i] == numString) {
         return i;
      }
   }
   return -1;
}

int main() {
   char oper;
   double num1 = 0, num2 = 0;

   while (true) {
      cout << "Enter num1, num2, operation in order. operation: +, -, *, / \n";
      int num1 = getNum();
      int num2 = getNum();
      if (num1 == -1 || num2 == -1) {
         cout << "Please enter correctly.\n";
         continue;
      }
      cin >> oper;
      switch (oper) {
      case '+':
         cout << "the sum of " << num1 << " and " << num2 << " is " << num1 +
            num2 << endl;
         break;
      case '-':
         cout << num1 << " minus " << num2 << " is " << num1 - num2 << endl;
         break;
      case '*':
         cout << num1 << " mutiplied by " << num2 << " is " << num1 *
            num2 << endl;
         break;
      case '/':
         cout << num1 << " divided by " << num2 << " is " << num1 /
            num2 << endl;
         break;
      default:
         break;
      }
   }
   return 0;
}
