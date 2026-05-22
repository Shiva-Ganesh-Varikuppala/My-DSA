#include<iostream>
using namespace std;

int main(void){

    int arr[] = {1, 2, 3, 4, 5,  6, 7, 8, 9};
    int target = 9;
    int sz = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < sz; i++){
        if(arr[i] == target){
            cout << i << endl;
        }
    }
    cout << "not found\n";
    return 0;
}