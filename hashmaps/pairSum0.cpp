//Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
//Array A can contain duplicate elements.
//While printing a pair, print the smaller element first.
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

void pairSumToZero(int* arr, int size){
    unordered_map<int, int> pairMap;
    for(int i=0; i<size; i++){
        pairMap[arr[i]]++;
    }
    for(int i=0; i<size; i++){
        int rev= -arr[i];
        if(pairMap.count(rev)> 0 && pairMap.count(arr[i]) >0){
            int freq= pairMap[rev]*pairMap[arr[i]];
            for(int j=0; j<freq; j++){
                cout<< min(rev, arr[i])<<" "<<max(rev, arr[i])<<endl;
            }
        }
        pairMap[arr[i]]= 0;
        pairMap[rev]= 0;
    }
}
int main(){
    int n;
    cout<< "Enter the size of the array : ";
    cin>>n;
    int *arr= new int[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    pairSumToZero(arr, n);
    delete[] arr;
    return 0;
}
