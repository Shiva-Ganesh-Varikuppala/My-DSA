#include<iostream>
using namespace std;


int binarySearch(int arr[], int target, int n){

    // for binary search the array must be sorted

    int st = 0;
    int end = n-1;
    
    while(st <= end){
        int mid = st + (end - st) / 2;
        if(arr[mid] == target){
            return mid;
        } else if (arr[mid] < target) {
            st = mid + 1;
        } else{
            end = mid - 1;
        }
    }
    return -1;
}


int main(void){
    
    int arr[] = {1, 2, 3, 4, 5, 7};
    int target = 4;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << binarySearch(arr, target, n);

    return 0;
}


// TC: O(log n)
// SC: O(1)
// and look in the recursion folder for recursive based binary search 