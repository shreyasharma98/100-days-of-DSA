/*
Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" .
In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .
This move will give him x points.
He plays the game until the board becomes empty .
But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off .
Can you help Gary in finding out the maximum points he receive grab from the game ?
Sample Input :
2
1 2
Sample Output :
2
*/
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>A;
int solve(int n,vector<int>A){
	int freq[1002], dp[1002];
    for(int i=0; i<n; i++){
        freq[A[i]]++;
    }
    //int dp[n+1];
    dp[0]= 0;
    dp[1]= freq[1];
    for(int i=2; i<=1000; i++){
        dp[i]= max((dp[i-2] + i*freq[i]), dp[i-1]);
    }
    int ans= dp[1000];
    return ans;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}
