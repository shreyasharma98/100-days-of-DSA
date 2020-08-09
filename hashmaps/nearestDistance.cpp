//Given an integer array, find and return the minimum distance between indexes of an element and its repetition
#include <iostream>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

int minDistance(int* arr, int n){
    int minlen= INT_MAX;
    unordered_map<int, int> hm;
    for(int i=0; i<n; i++){
        if(hm.count(arr[i])== 0){
            hm[arr[i]] = i;
        }
        else{
            minlen= min(minlen, i-hm[arr[i]]);
            hm[arr[i]]= i;
        }
    }
    return minlen;
}
int main(){
    int n=0;
    cout<< "Enter the size of the array : ";
    cin>>n;
    int *arr = new int[n];
    cout<< "Enter the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minDistance(arr, n);

}
