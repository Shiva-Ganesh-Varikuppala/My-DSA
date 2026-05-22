#include<iostream>
#include<vector>
using namespace std;

// binary search always requires sorted array to perform operations

int BS(vector<int> arr, int target, int st, int end){
    if(st <= end){
        int mid = st + (end - st) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            return BS(arr, target, mid+1, end);     // if we know that target is at the second half then we can call the recursion for the second half only
        else
            return BS(arr, target, st, mid-1);     // if we know that target is at the first half then we can call the recursion for the first half only
    }

    return -1;
}

int search(vector<int> &arr, int target){
    // this is basically a helper function: this acts as a wrapper around our recursive BS function, we have to give arr, target, st, end in main BS fn instead of giving all those params we create a helper fn that directly gives the result we need in only two params.
    return BS(arr, target, 0, arr.size() - 1);
}


int main(){
    vector<int> arr = {1, 2, 2, 3, 4,5, 6, 44};
    int target = 4;
    cout << search(arr, target);
    return 0;
}