#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int* val, int n, int sum){
    bool** dp= new bool*[n+1];
    for(int i=0; i<=n; i++){
        dp[i]= new bool[sum+1];
    }

    for(int j=0; j<=sum; j++){
        dp[0][j]= false;
    }
    for(int i=0; i<=n; i++){
        dp[i][0]= true;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            dp[i][j]= dp[i-1][j];
            if(j>= val[i-1]){
                dp[i][j]= dp[i][j] || dp[i-1][j-val[i-1]];
            }
        }
    }
    bool ans= dp[n][sum];
    for(int i=0; i<=n; i++)
        delete []dp[i];
    delete []dp;
    return ans;

}
int main(){
    int n;
    cin>>n;
    int* val= new int[n];
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    int sum;
    cin>>sum;
    bool ans= subsetSum(val, n, sum);
    if(ans== true)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
