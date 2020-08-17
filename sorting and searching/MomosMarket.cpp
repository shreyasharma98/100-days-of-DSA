/*
Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily.
After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos.
Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop) starting from the first shop.
She will visit the market for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily.
She cannot use the remaining money of one day on some other day.
But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.
Sample Input:
4
2 1 6 3
1
11
Sample Output:
3 2
*/
#include<bits/stdc++.h>
using namespace std;
int search(long arr[], int low, int high, long x){
    if(low>high){
        return -1;
    }
    if(x>= arr[high])
        return high;
    int mid= (low+ high)/2;
    if(arr[mid]== x){
        return mid;
    }
    if(mid>0 && arr[mid-1]<=x && x<arr[mid]){
        return mid-1;
    }
    if(x<arr[mid]){
        return search(arr, low, mid-1, x);
    }
    return search(arr, mid+1, high, x);
}
int main()
{
    int n;
    cin>>n;
    long* arr= new long[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    long* prefix= new long[n];
    prefix[0]= arr[0];
    for(int i=1; i<n; i++){
        prefix[i]= prefix[i-1] + arr[i];
    }
    int q;
    cin>>q;
    while(q--){
        long x;
        cin>>x;
        int s= search(prefix, 0, n-1, x);
        long val= x;
        if(s!= -1){
            val -= prefix[s];
        }
        cout<<s+1<< " "<<val<<endl;
    }
	return 0;
}

