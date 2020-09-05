/*
You are given a magrid S ( a magic grid ) having R rows and C columns.
Each cell in this magrid has either a Hungarian horntail dragon that our intrepid hero has to defeat, or a flask of magic potion that his teacher Snape has left for him.
A dragon at a cell (i,j) takes away |S[i][j]| strength points from him, and a potion at a cell (i,j) increases Harry's strength by S[i][j].
If his strength drops to 0 or less at any point during his journey, Harry dies, and no magical stone can revive him.
Harry starts from the top-left corner cell (1,1) and the Sorcerer's Stone is in the bottom-right corner cell (R,C).
From a cell (i,j), Harry can only move either one cell down or right i.e., to cell (i+1,j) or cell (i,j+1) and he can not move outside the magrid.
Harry has used magic before starting his journey to determine which cell contains what,
but lacks the basic simple mathematical skill to determine what minimum strength he needs to start with to collect the Sorcerer's Stone. Please help him once again.
Sample Input
3
2 3
0 1 -3
1 -2 0
2 2
0 1
2 0
3 4
0 -2 -3 1
-1 4 0 -2
1 -2 -3 0
Sample Output
2
1
2
*/
#include <bits/stdc++.h>
using namespace std;

int magicGrid(int** hm, int m, int n){
	int** dp= new int*[m];
    for(int i=0; i<m; i++){
        dp[i]= new int[n];
    }
    //base case
    dp[m-1][n-1]= 1;
    //base case
    for(int i= m-2; i>=0; i--){
        if(dp[i+1][n-1] - hm[i][n-1] < 1)
            dp[i][n-1]= 1;
        else
            dp[i][n-1]= dp[i+1][n-1] - hm[i][n-1];
    }
    //base case
    for(int j= n-2; j>=0; j--){
        if(dp[m-1][j+1] - hm[m-1][j] < 1)
            dp[m-1][j]= 1;
        else
            dp[m-1][j]= dp[m-1][j+1] - hm[m-1][j];
    }

    for(int i=m-2; i>=0; i--){
        for(int j=n-2; j>=0; j--){
            if(min(dp[i+1][j], dp[i][j+1]) - hm[i][j] < 1)
                dp[i][j]= 1;
            else
            	dp[i][j]= min(dp[i+1][j], dp[i][j+1]) - hm[i][j];
        }
    }
    int ans= dp[0][0];
    for(int i=0; i<m; i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int r, c;
        cin>>r>>c;
        int** hm= new int*[r];
        for(int i=0; i<r; i++){
            hm[i]= new int[c];
            for(int j=0; j<c; j++){
                cin>>hm[i][j];
            }
        }
        int ans= magicGrid(hm, r, c);
        cout<<ans<<endl;

    }
    return 0;
}

