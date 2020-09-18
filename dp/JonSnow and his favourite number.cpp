#include<bits/stdc++.h>
using namespace std;
int freq[2][1024];
int main(){
    int n, k, x, a;
    int m= 0;
    cin>>n>>k>>x;
    for(int i=0; i<n; i++){
        cin>>a;
        m= max(m, a);
        m= max(m, a^x);
        freq[0][a]++;
        freq[1][a]++;
    }
    m= min(m*2, 1023);
    for(int i=0; i<k; i++){
        int c=0;
        for(int j=0; j<=m; j++){
            if(freq[0][j] == 0)
                continue;
            if(c%2 == 0){
                int p= (freq[0][j]+1)/2;
                freq[1][(j^x)] += p;
                freq[1][j] -= p;
            }
            else{
                int p= freq[0][j]/2;
                freq[1][(j^x)] += p;
                freq[1][j] -= p;
            }
            c += freq[0][j];
        }
        for(int j=0; j<=m; j++)
            freq[0][j]= freq[1][j];
    }
        for(int i= m; i>=0; i--)
            if(freq[0][i]> 0) break;
        cout<<i<< " ";

        for(int i=0; i<=m; i++)
            if(freq[0][i] > 0) break;
        cout<<i;

}
