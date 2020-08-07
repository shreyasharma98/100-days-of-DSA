//You are given an array of integers that contain numbers in random order.
//Write a program to find and return the number which occurs the maximum times in the given input.
//If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
#include<iostream>
#include<unordered_map>
using namespace std;

int maxFrequency(int *arr, int size){
    int freq=0;
    int ele;
    unordered_map<int, int> freqMap;
    for(int i=0; i<size; i++){
        freqMap[arr[i]]++;
    }
    for(int i=0; i<size; i++){
        if(freq < freqMap[arr[i]]){
            freq= freqMap[arr[i]];
            ele= arr[i];
        }
    }
    return ele;
}
int main(){
    int n;
    cout<< "Enter the size of the array : ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans= maxFrequency(arr, n);
    cout<<ans<<endl;
    return 0;
}
