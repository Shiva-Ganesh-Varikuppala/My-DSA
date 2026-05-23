#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end){
    vector<int> temp;
    int i = st, j = mid + 1;
    while(i <= mid && j <= end){

        // "i - mid" is left half (one part)
        // "j - end" is right half (another part)  
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){    // for left half for the remaining elements
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end){   // for right half for the remaining elements
        temp.push_back(arr[j]);
        j++;
    }

    // copying elements from temporary to the org array
    for(int i = 0; i < temp.size(); i++)
        arr[i + st] = temp[i];
}

void MergeSort(vector<int> &arr, int st, int end){
    if(st < end){
        int mid = st + (end - st) / 2;

        MergeSort(arr, st, mid); // for the left half
        MergeSort(arr, mid + 1, end); // for the right half

        merge(arr, st, mid, end);

    }
}


int main(){

    vector<int> arr = {4, 3, 2, 6, 7, 1, 90};

    MergeSort(arr, 0, arr.size() - 1);

    for(int val : arr)
        cout << val << " ";
    cout << '\n';

    return 0;
}


/* 
TC: 

best case = O(n logn)
worst case = O(n log n)

SC: O(n)
 */