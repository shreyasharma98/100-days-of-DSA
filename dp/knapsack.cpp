/*A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi.
What is the maximum value V, that thief can take ?
Sample Input :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/
#include<bits/stdc++.h>
using namespace std;
int knapsack(int* weights, int* values, int n, int maxWeight){
    int dp[2][maxWeight+1];
    for(int j=0; j<=maxWeight; j++)
        dp[0][j]= 0;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=maxWeight; j++){
            if(i%2 == 0){
                if(weights[i-1] <= j)
                    dp[0][j]= max(values[i-1]+ dp[1][j-weights[i-1]], dp[1][j]);
                else
                    dp[0][j]= dp[1][j];
            }
            else{
                if(weights[i-1] <= j)
                    dp[1][j]= max(values[i-1]+ dp[0][j-weights[i-1]], dp[0][j]);
                else
                    dp[1][j]= dp[0][j];
            }
        }
    }
    if(n%2== 0)
        return dp[0][maxWeight];
    else
        return dp[1][maxWeight];
}

int main(){
  int n;
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);
}
