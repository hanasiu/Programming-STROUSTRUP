#include <iostream>

using namespace std;

int main() {
   char oper;
   double num1 = 0, num2 = 0;
   cout << "Enter num1, num2, operation in order. operation: +, -, *, / \n";
   while (cin >> num1 >> num2 >> oper) {
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
