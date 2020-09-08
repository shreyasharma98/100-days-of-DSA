/*A thief wants to loot houses. He knows the amount of money in each house.
He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Sample Input :
6
5 5 10 100 10 5
Sample Output :
110
*/

#include<bits/stdc++.h>
using namespace std;
int getMaxMoney(int arr[], int n){
	int* dp= new int[n];
    dp[0]= arr[0];
    dp[1]= max(arr[1], arr[0]);
    for(int i=2; i<n; i++){
        dp[i]= max(arr[i]+dp[i-2], dp[i-1]);
    }
    int ans= dp[n-1];
    delete [] dp;
    return ans;
}
int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}
