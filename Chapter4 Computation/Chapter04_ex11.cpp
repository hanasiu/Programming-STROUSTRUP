#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
  vector<int> primeList = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  for (int i = 0; i < primeList.size(); ++i) {
    if (num != primeList[i] && num % primeList[i] == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int number = 0;
  while (cin >> number) {
    bool check = isPrime(number);
    if (check) {
      cout << number << " is a prime number" << endl;
    } else {
      cout << number << " is not a prime number" << endl;
    }
  }
  return 0;
}
