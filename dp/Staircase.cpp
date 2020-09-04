/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input :
4
Output :
7
*/
#include <iostream>
using namespace std;
long staircase(int n)
{
	long* dp= new long[n+1];
    dp[0]= 1;
    dp[1]= 1;
    dp[2]= 2;
    for(int i=3; i<=n; i++){
        dp[i]= dp[i-1]+ dp[i-2] + dp[i-3];
    }
    long ans= dp[n];
    delete [] dp;
    return ans;
}
int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
