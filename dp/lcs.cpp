/* Given two strings S1 and S2 with lengths M and N respectively, find the length of the longest common subsequence.
Sample Input:
adebc
dcadb
Sample Output:
3
*/
#include<bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2)
{
	int m= s1.length();
    int n= s2.length();
    int** dp= new int*[m+1];
    for(int i=0; i<=m; i++){
        dp[i]= new int[n+1];
    }
    for(int i=0; i<=m; i++)
        dp[i][0]= 0;
    for(int i=0; i<=n; i++)
        dp[0][i]= 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[m-i]== s2[n-j])
                dp[i][j]= 1+ dp[i-1][j-1];
            else
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int ans= dp[m][n];
    for(int i=0; i<=m; i++)
        delete [] dp[i];
    delete []dp;
    return ans;
}
