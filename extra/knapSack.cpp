#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(
                    val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
        int W;
        int n;
        int weight[n];
        int value[n];
	    cin>>W;
	    cin>>n;
	    for(int j=0; j<n; j++){
	        cin>>value[j];
	    }
	    for(int k=0; k<n; k++){
	        cin>>weight[k];
	    }
	    int ans= knapSack(W, weight, value, n);
        cout<<ans;
	}
	return 0;
}
