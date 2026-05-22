#include <iostream>
using namespace std;

int countDigits(int n) {
  if (n == 0) {
    return 0;
  } else {
    return 1 + countDigits(n / 10);
  }
}

int main() {
  int n = 4321098;

  cout << countDigits(n);
  return 0;
}