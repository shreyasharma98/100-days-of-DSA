/*
Given a n*m matrix which contains only 0s and 1s,
find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1
*/
#include<bits/stdc++.h>
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int dp[row][col];

    for(int i=0; i<row; i++){
        if(arr[i][0]== 0)
            dp[i][0]= 1;
        else
            dp[i][0]= 0;
    }
    for(int j=1; j<col; j++){
        if(arr[0][j]== 0)
            dp[0][j]= 1;
        else
            dp[0][j]= 0;
    }
    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            if(arr[i][j]== 0){
                int k1= dp[i-1][j-1];
                int k2= dp[i-1][j];
                int k3= dp[i][j-1];
                dp[i][j]= min(k1, min(k2, k3)) + 1;
            }
            else
                dp[i][j]= 0;
        }
    }
    int ans= INT_MIN;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(dp[i][j] > ans){
                ans= dp[i][j];
            }
        }
    }
    return ans;
}
int main()
 {
  int **arr,n,m,i,j;
  cin>>n>>m;
  arr=new int*[n];
  for(i=0;i<n;i++)
      {
       arr[i]=new int[m];
      }
  for(i=0;i<n;i++)
     {
      for(j=0;j<m;j++)
	    {
	     cin>>arr[i][j];
	    }
     }
  cout << findMaxSquareWithAllZeros(arr,n,m) << endl;
  delete arr;
  return 0;
}
