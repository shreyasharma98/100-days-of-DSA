//You are given an array of unique integers that contain numbers in random order.
//Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
//You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
//Best solution takes O(n) time.
//If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> largestSeq(int *arr, int size){
    unordered_map<int, bool> seq;
    for(int i=0; i<size; i++){
        seq[arr[i]]= true;
    }
    int maxlen=0;
    int start= 0;
    int curr, prev, len;
    for(int i=0; i<size; i++){
        curr= arr[i];
        prev= curr-1;
        len= 0;
        if(seq[curr]== true){
            while(seq.count(curr) > 0){
                len++;
                seq[curr]= false;
                curr++;
            }
            while(seq.count(prev) > 0){
                len++;
                seq[prev]= false;
                prev--;
            }
            if(len >maxlen){
                maxlen= len;
                start= prev+1;
            }
            if(len == maxlen){
                int p= -1, q= -1, temp= prev+1;
                for(int i=0; i<size; i++){
                    if(arr[i]== start && p== -1)
                        p= i;
                    if(arr[i]== temp && q== -1)
                        q= i;
                }
                if(p> q){
                    start= temp;
                }
            }
        }
    }
    vector<int> v;
    for(int i=0; i<maxlen; i++){
        v.push_back(start);
        start++;
    }
    return v;
}
int main(){
    int n;
    cout<< "Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<< "Enter array elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> ans= largestSeq(arr, n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
