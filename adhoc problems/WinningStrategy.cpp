/*
Our college team is going to the sports fest to play a football match with our coach. There are n players in our team, numbered from 1 to n.
The coach will know the position of another team hence create a winning strategy.
\He creates the position of every player in a specific order so that we will win and then he starts swapping two players at a time to form the positions.
He swaps payers in such a way that it can't be understood by another team:
1. Any player can swap with the player directly at front him
2. One player can swap at most with two other players
If the specific order is formed then our team will win otherwise we will lose

Sample Input1:
5
2 1 5 3 4
Sample Output1:
YES
3
Sample Input2:
5
2 5 1 3 4
Sample Output3:
NO
Explaination
In the First Sample case,
    Initial state: 1 2 3 4 5
    Three moves required to form this order:
    1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 5 3 4 -> 2 1 5 3 4
In the second case, no way to form this specific order
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int s= 0; //totalSwap
    for(int i= n-1; i>=0; i--){
        if(arr[i]== i+1){
    		if(i==0){
                cout<<"YES"<<endl;
                cout<<s<<endl;
    		}
        }
        else if(i-1>= 0 && arr[i-1]== i+1){
            swap(arr[i-1], arr[i]);
            s++;
        }
        else if(i-2 >= 0 && arr[i-2]== i+1){
            swap(arr[i-2], arr[i-1]);
            swap(arr[i-1], arr[i]);
            s+= 2;
        }
        else{
            cout<<"NO"<<endl;
            break;
        }
    }
    return 0;
}
