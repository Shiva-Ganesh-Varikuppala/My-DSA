#include<iostream>
using namespace std;


int main(void){

    int arr[] = {5, 1, 4, 2,  8};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n - 1; i++){
        bool swapped = false;
        for(int j = 0; j < n-i-1; i++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}