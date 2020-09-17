/* For a string of n bits x1,x2,x3,...,Xn the adjacent bit count of the string (AdjBC(x)) is given by

X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn

which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
AdjBC(011101101) = 3
AdjBC(111101101) = 4
AdjBC(010101010) = 0
Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2ⁿ) that satisfy AdjBC(x) = k.
For example, for 5 bit strings, there are 6 ways of getting AdjBC(x) = 2:
11100, 01110, 00111, 10111, 11101, 11011
Sample Input
10
1 5 2
2 20 8
3 30 17
4 40 24
5 50 37
6 60 52
7 70 59
8 80 73
9 90 84
10 100 90
Sample Output
1 6
2 63426
3 1861225
4 168212501
5 44874764
6 160916
7 22937308
8 99167
9 15476
10 23076518
*/
sing namespace std;
#define MOD 1000000007
long long dp[101][101][2];
long long adjacentBitCounts(int n,int k,int first){
    if(dp[n][k][first] >= 0)
        return dp[n][k][first];

    if(n == 1){
        if(k == 0){
            dp[n][k][first] = 1;
            return 1;
        }
        else{
            dp[n][k][first] = 0;
            return 0;
        }
    }

    if(k < 0){
        dp[n][k][first] = 0;
        return 0;
    }

    if(first == 1){
        long long ans1 = adjacentBitCounts(n-1,k-1,1);
        long long ans2 = adjacentBitCounts(n-1,k,0);
        dp[n][k][first] = (ans1 + ans2)%MOD;
    }
    else{
        long long ans1 = adjacentBitCounts(n-1,k,1);
        long long ans2 = adjacentBitCounts(n-1,k,0);
        dp[n][k][first] = (ans1 + ans2)%MOD;
    }

    return dp[n][k][first];
}

long long countBits(int n,int k){
    long long ans = (adjacentBitCounts(n,k,0)+adjacentBitCounts(n,k,1))%MOD;
    return ans;
}

int main(){
    int t;
    cin >> t;

    for(int i = 0; i <= 101; i++){
        for(int j = 0; j <= 101; j++){
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }

    while(t--){
        int a,n,k;
        cin >> a >> n >> k ;
        cout<<a<<" "<<countBits(n,k)<<endl;
    }
    return 0;

}
