#include<iostream>
using namespace std;

// binary search - it always requires sorted array for searching

int bs(int arr[], int target, int sz){
    int left = 0;
    int right = sz - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    // if not found
    return -1;
}

int main(void){

    int arr[] = {1, 2, 3, 4, 5,  6, 7, 8, 9};
    int target = 9;
    int sz = sizeof(arr) / sizeof(arr[0]);

    cout << bs(arr, target,  sz);

    return 0;
}