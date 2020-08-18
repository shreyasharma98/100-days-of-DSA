/*
We say that two integers x and y have a variation of at least K, if |x − y| ≥ K (the absolute value of their difference is at least K).
Given a sequence of N integers a1,a2,...,aN and K, the total variation count is the number of pairs of elements in the sequence with variation at least K,
i.e. it is the size of the set of pairs

{(i,j)|1≤i<j≤N and|ai−aj|≥K}

For example if K = 1 and the sequence is 3,2,4 the answer is 3. If K = 1 and the sequence is 3, 1, 3 then the answer is 2.

Your task is to write a program that takes a sequence and the value K as input and computes the total variation count.
Sample Input
3 1
3 1 3
Sample Output
2
*/
#include<bits/stdc++.h>
using namespace std;

long variationPairs(int arr[], int n, int k){
    sort(arr, arr+n);
    int i=0, j=1;
    long count = 0;
    while(j<n){
        if((arr[j] -  arr[i]) >= k){
            count += (n-j);
            i++;
        }else{
            j++;
        }
    }
    return count;
}
int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    long count= variationPairs(arr, n, k);
    cout<<count<<endl;
    return 0;
}
