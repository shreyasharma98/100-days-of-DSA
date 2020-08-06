//You are given with an integer k and an array of integers that contain numbers in random order.
//WAP to find k largest numbers from given array. You need to save them in an array and return it.
/* METHOD-1 using bubble sort 1) Modify Bubble Sort to run the outer loop at most k times.
2) Print the last k elements of the array obtained in step 1.
Time -O(nk)
METHOD-2 using sorting O(n logn)
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> klargest(int arr[], int size, int k){
    priority_queue<int, vector<int>, greater<int> > min_pq;
    vector<int> v;
    for(int i=0; i<k; i++){
        min_pq.push(arr[i]);
    }
    for(int i=k; i<size; i++){
        if(arr[i] > min_pq.top()){
            min_pq.pop();
            min_pq.push(arr[i]);
        }
    }
    for(int i=0; i<k; i++){
        v.push_back(min_pq.top());
        min_pq.pop();
    }
    return v;
}
int main(){
    int n;
    cout<< "Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<< "Enter array elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cout<< "Enter the value of k : ";
    cin>>k;
    vector<int> ans= klargest(arr, n, k);
    for(int i=0 ;i<ans.size(); i++){
        cout<<ans.at(i)<< " ";
    }
    return 0;
}
//time- O(n logk)
//space-O(k)
