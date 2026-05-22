#include <iostream>
using namespace std;

int linearSearch(int arr[], int target, int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i;
    }
}
    return -1;
}

int main(void) {

  int arr[] = {1, 2, 6, 5, 4, 3};
  int n = 6;
  int target = 5;

  cout << linearSearch(arr, target, n);

  return 0;
}

// TC: O(n)
// SC: O(1)