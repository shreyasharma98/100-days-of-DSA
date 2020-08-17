/*Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
To prevent the cows from hurting each other,
FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible.
What is the largest minimum distance?
Sample Input:
1
5 3
1
2
8
4
9
Sample Output:
3
*/
#include<bits/stdc++.h>
using namespace std;

bool check(int cows, long long positions[], int n, long long distance){
    int count= 1;
    long long last_position= positions[0];
    for(int i=1; i<n; i++){
        if(positions[i]- last_position >= distance){        //if difference of array elements is greater than distance
            last_position= positions[i];
            count++;
        }
        if(count == cows){      //if all cows placed
            return true;
        }
    }
    return false;
}
int main() {
	int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n>>c;
        long long positions[n];
        for(int i=0; i<n; i++){
            cin>> positions[i];
        }
        sort(positions, positions+n);
        long long start=0; //min distance
        long long end= positions[n-1]- positions[0]; // max distance
        long long ans= -1;
        while(start <= end){  //binary search
            long long mid= start + (end - start)/2;
            if(check(c,positions, n, mid)){
                ans= mid;
                start= mid+1;
            }
            else{
                end= mid-1;
            }
        }
        cout<<ans<<endl;
    }
}

