/*
You are given two binary strings a and b of the same length.
You can perform the following two operations on the string :
    Swap any two bits at indices i and j respectively (1≤i,j≤n), the cost of this operation is |i−j|, that is, the absolute difference between i and j
    Select any arbitrary index i (1≤i≤n) and flip (change 0 to 1 or 1 to 0) the bit at this index. The cost of this operation is 1
Find the minimum cost to make the string a equal to b.
It is not allowed to modify string b.
Input:
4
0101
0011
Output :
1
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    int cost= 0;

    for(int i=0; i<n; ){
        if(s[i] != t[i]){
            //either swap or flip
             if(i+1 < n && s[i+1] != s[i] && s[i+1] != t[i+1]){
                i += 2;
             }else{
            i++;
            }
            cost++;
        }else{
            i++;
        }
    }
    cout<< cost<<endl;
    return 0;
}
