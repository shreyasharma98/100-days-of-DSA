/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}.
You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).
*/
#include<bits/stdc++.h>
using namespace std;

int coinChange(int denominations[], int numDenominations, int value, int** dp){
    if(value== 0)
        return 1;

    if(value < 0)
        return 0;

    if(numDenominations == 0)
        return 0;

    if(dp[value][numDenominations] > -1)
        return dp[value][numDenominations];

    int first= coinChange(denominations, numDenominations, value- denominations[0], dp);
    int second= coinChange(denominations+1, numDenominations-1, value, dp);
    dp[value][numDenominations]= first + second;

    return dp[value][numDenominations];

}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){

	int** dp= new int*[value+1];
    for(int i=0; i<=value; i++){
        dp[i]=new int[numDenominations+1];
        for(int j=0; j<=numDenominations; j++){
            dp[i][j]= -1;
        }
    }

	return coinChange(denominations, numDenominations, value, dp);
}
int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}
