#include<iostream>
#include <utility>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int st, int end){

  int pivot = arr[end];
  int idx = st - 1;

  for(int j = st; j < end; j++){
	if(arr[j] <= pivot){
		idx++;
		swap(arr[idx], arr[j]);
	}
  }

  swap(arr[idx+1], arr[end]);

  return idx+1;
}

void quicSort(vector<int> &arr, int st, int end){
	if(st < end){
		int pivIdx = partition(arr, st, end);

		quicSort(arr, st, pivIdx-1);
		quicSort(arr, pivIdx + 1, end);
	}
}


int main(){
	vector<int> arr = {5, 3, 2, 6};
	quicSort(arr, 0, arr.size()-1);
	
	for(int val : arr){
		cout << val << " ";
	}
	cout << endl;

	return 0;
}