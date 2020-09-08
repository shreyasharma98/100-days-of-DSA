/*
Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5
*/
#include<bits/stdc++.h>
using namespace std;
int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int m= (pow(10,9)) +7;
    long long dp[n+1];
    memset(dp, 0, n+1);
    dp[0]= 1;
    dp[1]= 1;
    for(int i=2; i<=n; i++){
        long long ans= 0;
        for(int j= 1; j<=i; j++){
            ans= (ans%m + ((dp[i-j]%m *dp[j-1]%m)%m)%m)%m;
        }
        dp[i]= ans;
    }
	int x= dp[n] % m;
    return x;
}
int main()
{
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}
