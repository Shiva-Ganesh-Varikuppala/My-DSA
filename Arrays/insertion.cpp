#include<iostream>
using namespace std;

int main(){

    int arr[100]= {1, 2, 3, 4, 5};

    int sz = 5;
    int idx = 2;
    int val = 6;

    // shifting elements to right to give place to the new element
    for(int i = sz; i > idx; i--){
        arr[i] = arr[i - 1];
    }

    // inserting value
    arr[idx] = val;     sz++;

    // printing array
    for(int i = 0; i < sz; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

// TC: insertion at beginning is O(n)
// TC: insertion at end is O(1)