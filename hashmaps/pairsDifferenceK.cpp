//You are given with an array of integers and an integer K.
//Write a program to find and print all pairs which have difference K.
//Take difference as absolute.
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void pairDifferenceK(int* arr, int size, int k){
    unordered_map<int, int> present;
    for(int i=0; i<size; i++){
        present[arr[i]]++;
    }
    if(k == 0){
        for(int i=0; i<size; i++){
            int x= present[arr[i]];
            for(int j=0; j<x*(x-1)/2; j++){
                cout<<arr[i]<< " "<<arr[i]<<endl;
            }
            present[arr[i]]=0;
        }
        return;
    }
    for(int i=0; i<size; i++){
        int curr= arr[i];
        int prev1= curr-k;
        int prev2= curr+k;
        if(present.count(prev1) > 0){
            int freq= present[curr]* present[prev1];
            for(int i=0; i<freq; i++){
                cout<< min(prev1,curr) << " " << max(prev1, curr)<<endl;
            }
        }
        if(present.count(prev2) > 0){
            int freq= present[curr]* present[prev2];
            for(int i=0; i<freq; i++){
                cout<< min(prev2,curr) << " " << max(prev2, curr)<<endl;
            }
        }
        present[curr]=0;
    }
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
	int k;
	cout<< "Enter k : ";
	cin >> k;
	pairDifferenceK(input, n, k);
}
