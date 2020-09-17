/*Vanya has been studying all day long about sequences and other Complex Mathematical Terms. She thinks she has now become really good at it.
So, her friend Vasya decides to test her knowledge and keeps the following challenge it front of her:
Vanya has been given an integer array A of size N. Now, she needs to find the number of increasing sub-sequences of this array with length ≥1 and GCD=1.
A sub-sequence of an array is obtained by deleting some (or none) elements and maintaining the relative order of the rest of the elements.
As the answer may be large, print it Modulo 109+7
She finds this task really easy, and thinks that you can do it too. Can you?
Sample Input
3
1 2 3
Sample Output
5
*/


#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int dp[501][101], arr[501];
int main(){
    int n, x, m=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        m= max(arr[i], m);
        dp[i][arr[i]]= 1;
    }
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(arr[i] > arr[j]){
                for(int k=1; k<=m; k++){
                    x= __gcd(k, arr[i]);
                    dp[i][x] = ((dp[i][x]%mod) + (dp[j][k]%mod))%mod;
                }
            }
        }
    }
    int ans= 0;
    for(int i=0; i<n; i++){
        ans = ((ans%mod)+ (dp[i][1] %mod)) %mod;
    }
    cout<<ans;
    return 0;
}
