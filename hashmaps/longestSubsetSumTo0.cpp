//Given an array consisting of positive and negative integers,
// find the length of the longest subarray whose sum is zero.
#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfSubsetSumTo0(int* arr, int size){
    unordered_map<int, int> present;
    for(int i=0; i<size; i++){
        arr[i] += arr[i-1];
    }
    int maxlen= 0;
    for(int i=0; i<size; i++){
        if(arr[i] ==0)
            maxlen= i+1;
        else if(present.count(arr[i]) > 0){
            if(maxlen < i-present[arr[i]])
                maxlen= i-present[arr[i]];
        }
        else{
            present[arr[i]] = i;
        }
    }
    return maxlen;
}
int main() {
	int n;
	cout<< "Enter the size of the array : ";
	cin >> n;
	int *input = new int[n];
	cout<< "Enter the array : ";
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int ans= lengthOfSubsetSumTo0(input, n);
	cout<<ans<<endl;
	return 0;
}
