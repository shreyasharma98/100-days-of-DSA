/*
Professor Jain has a class full of notorious students. To get anything done from them is a herculean task. Prof Jain wanted to organize a test.
He gave this responsibility to Aahad. Aahad did an excellent job of organizing the test. As a reward, the professor gave him an sequence of numbers to play with.
But Aahad likes playing with "interesting" sequence of numbers, which are sequences that have equal elements.
Now, the problem is - Prof Jain has a sequence with elements, and that sequence isn't always "interesting”. To ensure sequence has equal elements, Prof Jain has 2 options:
1) Choose two elements of sequence . DECREASE the first element by 1 and INCREASE the second element by 1. This operation costs 'k' coins.
2) Choose one element of array and INCREASE it by 1. This operation costs 'l' coins.
What’s the minimum number of coins Prof Jain needs to turn his sequence into a “interesting" sequence for Aahad?

Sample Input:
4 1 2
3 4 2 2
Sample Output :
3
Explanation Output :
The professor has a sequence with 4 elements. To perform the first operation, they must pay 1 coin and to perform the second operation, they must pay 2 coins.
The optimal strategy is:
-Perform the second operation on the fourth element. Now the sequence is {3, 4, 2, 3}. This costs 2 coins.
-Perform the first operation on the second and third element. The sequence is now "interesting", and it looks like {3, 3, 3, 3}. This costs 1 coin.
The total amount of coins needed is 2 + 1 = 3.
*/
#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n, k, l;
    cin>>n>>k>>l;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int mini= *min_element(arr, arr+n);
    int maxi= *max_element(arr, arr+n);
    //int ele= mini;
    int minCost= INT_MAX;
    for(int ele= mini; ele<= maxi; ele++){
        int inc= 0;
        int dec= 0;
        for(int i=0; i<n; i++){
            if(arr[i] < ele){
                int diff= ele- arr[i];
                inc += diff;
            }
            else{
                int diff2= arr[i]- ele;
                dec += diff2;
            }
        }
        if(inc >= dec){
            int cost= (dec * k)+ ((inc-dec)*l);
            if(cost < minCost){
                minCost= min(minCost, cost);
            }
        }
        else{
            continue;
            //ele++;
        }
        //ele++;
    }
    cout<<minCost<<endl;
}
