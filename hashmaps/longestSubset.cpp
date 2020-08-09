//Given an array, find and return the length of longest subarray containing equal number of 0s and 1s.
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int longestSubset(int* arr, int n){
    for(int i=0; i<n; i++){
        if(arr[i] == 0)
            arr[i]= -1;
    }
    int maxlen= -1, sum= 0;
    unordered_map<int, int> m;
    m[0]= -1;
    for(int i=0; i<n; i++){
        sum += arr[i];
        /*if(ourMap.count(sum) == 0){
            ourMap[sum]= i;
        }
        else{
            maxlen= max(maxlen, i-ourMap[sum]);
        }*/
        if(m.find(sum) != m.end()){
            if(maxlen < i-m[sum])
                maxlen= i-m[sum];
        }
        else
            m[sum]= i;
    }
    return maxlen;
}
int main() {
    	int n=0;
    	cout<< "Enter the size of the array : ";
    	cin>>n;
    	int *arr = new int[n];
    	cout<< "Enter the array : ";
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    	}

    	cout << longestSubset(arr,n);


}
