/* Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city
and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities),
also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Sample Input
3
0 0 1
3 1 1
6 0 9
Sample Output
4.675445
*/
#include <bits/stdc++.h>
using namespace std;
#define N 3005
//#define inf 1000000000000;
double dp[N];
double x[N], y[N], f[N];

double get_dist(int a, int b){
    return sqrt((x[a]- x[b])* (x[a]- x[b]) + (y[a]- y[b])* (y[a]- y[b]));
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x[i]>>y[i]>>f[i];
    }
    for(int i=0; i<n; i++){
        dp[i]= INT_MIN;
    }
    dp[0]= f[0];
    for(int i=1; i<n; i++){

        for(int j=0; j<i; j++){
            double d= get_dist(i, j);
            dp[i]= max(dp[i], dp[j]- d);
        }
        dp[i]+=f[i];
    }
    cout<<fixed<<setprecision(6)<<dp[n-1]<<endl;
    return 0;
}
