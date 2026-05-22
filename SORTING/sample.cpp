#include <algorithm>
#include <iostream>
using namespace std;

// ALL SORTING ALGORITHMS

// 1. bubble sort
void bubbleSort(int arr[], int sz) {
  for (int i = 0; i < sz - 1; i++) {
    for (int j = 0; j < sz - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// look at the optimised part after done


// 2. selection sort
void selectionSort(int arr[], int sz){
    for(int i = 0; i < sz - 1; i++){
      int minIdx = i;
      for(int j = i + 1; j < sz; j++){
        if(arr[j] < arr[minIdx]){
          minIdx = j;
        }
      }
      swap(arr[i], arr[minIdx]);
    }
}


// insertion sort
void insertionSort(int arr[], int sz){
    for(int i = 1; i < sz; i++){
      int key = arr[i];
      int j = i - 1;

      while(j >= 0 and arr[j] > key){
        arr[j+1] = arr[j];
        j--;
      }
      arr[j+1] = key;
    }
}

int main(void) {
  // for bubble sort
  int arr[] = {3, 2, 1, 7, 6};
  int sz = 5;

  bubbleSort(arr, sz);

  for (int sz : arr) {
    cout << sz << " ";
  }
  cout << endl;
  
  selectionSort(arr, sz);
  
  for (int sz : arr) {
    cout << sz << " ";
  }
  cout << endl;
  
  insertionSort(arr, sz);
  for (int sz : arr) {
    cout << sz << " ";
  }
  cout << endl;
  return 0;
}