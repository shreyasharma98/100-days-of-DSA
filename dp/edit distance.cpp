/* Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings.
Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character
Sample Input 1:
abc
dc
Sample Output :
2
*/
#include<bits/stdc++.h>
using namespace std;
int editDistance(string s1, string s2){
    int m= s1.length();
    int n= s2.length();
    int** dp= new int*[m+1];
    for(int i=0; i<=m; i++){
        dp[i]= new int[n+1];
    }
    for(int i=0; i<=m; i++)
        dp[i][0]= i;
    for(int i=0; i<=n; i++)
        dp[0][i]= i;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[m-i]== s2[n-j])
                dp[i][j]= dp[i-1][j-1];
            else{
                int a= dp[i-1][j];
                int b= dp[i][j-1];
                int c= dp[i-1][j-1];
                dp[i][j]= min(a, min(b,c)) + 1;
            }
        }
    }
    int ans= dp[m][n];
    for(int i=0; i<=m; i++)
        delete [] dp[i];
    delete []dp;
    return ans;

}
