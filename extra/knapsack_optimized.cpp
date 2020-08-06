//time- O(nW)
//space O(W)
#include <bits/stdc++.h>
using namespace std;
int knapsack2(int W, int wt[], int val[], int n)
{
    int dp[2][W+1];
    for(int i=0; i<=W; i++){
        dp[0][i]= 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(i%2 == 0){
                if(wt[i-1]<= j)
                    dp[0][j]= max(val[i-1]+ dp[1][j- wt[i-1]], dp[1][j]);
                else
                    dp[0][j]= dp[1][j];
            }
            else{
                if(wt[i-1]<= j)
                    dp[1][j]= max(val[i-1]+ dp[0][j- wt[i-1]], dp[0][j]);
                else
                    dp[1][j]= dp[0][j];
            }
        }
    }
    if(n%2== 0)
        return dp[0][W];
    else
        return dp[1][W];
}

int main() {
	//code
    int W;
    int n;
    cout<< "Enter n : ";
    cin>>n;
    cout<< "Enter max Weight : ";
    cin>>W;
    int weight[n];
    int value[n];
     cout<<"Enter the weights of the "<<n<< " items : ";
    for(int k=0; k<n; k++){
        cin>>weight[k];
    }
    cout<< "Enter the values of the "<<n<< " items : ";
    for(int j=0; j<n; j++){
        cin>>value[j];
    }
    int ans= knapsack2(W, weight, value, n);
    cout<<ans;
	return 0;
}
