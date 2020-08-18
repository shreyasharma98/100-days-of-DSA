/*
Find and return the element of array which has maximum occurrences of digit k*/

#include<bits/stdc++.h>
using namespace std;

int countdigits(int n, int k){
    if(n==0)
        return 0;
    int digit= n%10;
    if(digit == k)
        return 1+ countdigits(n/10, k);
    return countdigits(n/10, k);
}
int main(){
    int n;
    cin>>n;
    long long arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    int ans= -1;
    int index= -1;
    for(int i=0; i<n; i++){
        int temp= countdigits(arr[i], k);
        if(temp > ans){
            ans= temp;
            index= i;
        }
    }
    cout<<arr[index];
}
