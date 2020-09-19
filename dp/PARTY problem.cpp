/*You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
Sample Input
50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9

50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2

0 0
Sample Output
49 26
48 32
*/
#include<bits/stdc++.h>
using namespace std;
int w[101], val[101], dp[101][501];
int main(){
    int W, n, ans;
    while(1){
        cin>>W>>n;
        if(W==0 && n==0)
            break;
        w[0]= 0;
        val[0]= 0;
        for(int i=1; i<=n; i++)
            cin>>w[i]>>val[i];
        for(int i=0; i<=n; i++)
            dp[i][0]= 0;
        for(int j=0; j<=W; j++)
            dp[0][j]= 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=W; j++){
                if(w[i] > j)
                    dp[i][j]= dp[i-1][j];
                else
                    dp[i][j]= max(dp[i-1][j], dp[i-1][j-w[i]]+ val[i]);
            }
        }
        ans= W;
        for(int i=0; i<W; i++){
            if(dp[n][i]== dp[n][W]){
                ans= i;
                break;
            }
        }
        cout<<ans<<" "<<dp[n][W]<<endl;
    }
}
