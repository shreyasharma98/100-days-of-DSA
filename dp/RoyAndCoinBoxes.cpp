/*Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.
After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/
#include<bits/stdc++.h>
using namespace std;
long int days[1000001];
long int strt[1000001], en[1000001], ans[1000001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, l, r, q, c=0;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>l>>r;
        strt[l]++;      //noting the times starting box was kth box
        en[r]++;        //noting the times ending box was kth box
    }
    for(int i=1; i<=n; i++){
        c += strt[i];
        days[i]= c;     //no. of coins in the box is same as no. of days the coin was put in the box
        c -= en[i];
    }
    for(int i=1; i<=n; i++)
        ans[days[i]]++;     //boxes w exact i coins

    for(int i=n-1; i>0; i--)
        ans[i] += ans[i+1];     //boxes w atleast i coins

    cin>>q;
    while(q--){
        c=0;
        cin>>x;
        cout<<ans[x]<<endl;
    }
    return 0;
}
