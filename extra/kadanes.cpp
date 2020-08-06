//Write an efficient program to find the sum of contiguous subarray within a 1-D array of numbers which has the largest sum.
#include<iostream>
using namespace std;
int maxSubArraySum(int arr[], int size){
    int best_so_far= 0, maxSum= 0;
    //int si=0, ei=0,s=0;
    for(int i=0; i<size; i++){
        maxSum += arr[i];
        if(maxSum < 0){
            maxSum = 0;
            //s= i+1;
        }
        else if(maxSum > best_so_far){
            best_so_far= maxSum;
            si= s;
            //ei= i;
        }
    }
    return best_so_far;
    //cout<< "Max Contiguous sum is : "<<best_so_far<<endl;
    //cout<< "starting index : "<<si<<endl<< "ending index : "<<ei;
}
int main(){
    int n;
    cout<< "Enter the size of the Array : ";
    cin>>n;
    int arr[n];
    cout<< "Enter array elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans= maxSubArraySum(arr, n);
    cout<< "Max sub array sum is : "<<ans;

}
