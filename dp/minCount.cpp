/*
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}.
Output will be 1, as 1 is the minimum count of numbers required.
Sample Input 1 :
12
Sample Output 1 :
3
Sample Input 2 :
9
Sample Output 2 :
1
*/
#include <bits/stdc++.h>
using namespace std;
int minCount(int n)
{
    int* dp= new int[n+1];
    dp[0]= 0;
    dp[1]= 1; 		//1^2
    dp[2]= 2;		//1^2 + 1^2
    dp[3]= 3;		//1^2 + 1^2 + 1^2
    for(int i=4; i<= n; i++){
        dp[i]= i;		//1^2 + 1^2 + ...
        for(int j= floor(sqrt(i)); j>=1; j--){
            int sq= j*j;
            if(sq > i)
                break;
            else
                dp[i]= min(dp[i], 1+ dp[i- sq]);
        }
    }
    int ans= dp[n];
    delete [] dp;
    return ans;
}
int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}
