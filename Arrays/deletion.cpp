#include<iostream>
using namespace std;

int main(){

    int arr[100] = {1, 2, 3, 4, 5};
    int sz = 5;
    int idx = 2;

    // shifiting elements to the left
    for(int i = 0; i < sz-1; i++)
        arr[i] = arr[i+1];

    sz--;

    // printing array
    for(int i = 0; i < sz; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

// TC: delete from beginning is O(n)
// TC: delete from end is O(1)