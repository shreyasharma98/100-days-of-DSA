//Given an array of positive integers. The task is to find inversion count of array.
//time- O(n logn)
//space- O(n)
#include<bits/stdc++.h>
using namespace std;

int _merge(int arr[], int temp[], int si, int mid, int ei){
    int i= si, j= mid, k= si;
    int inv_count= 0;
    while((i<=mid-1) && (j<=ei)){
        if(arr[i]<= arr[j]){
            temp[k]= arr[i];
            k++;
            i++;
        }
        else{
            temp[k]= arr[j];
            k++;
            j++;
            inv_count += (mid-i); //if a[i] is greater than a[j], then there are (mid – i) inversions.
            //because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
        }
    }
    while(i <= mid-1)
        temp[k++]= arr[i++];
    while(j <= ei)
        temp[k++]= arr[j++];
    for(i=si; i<=ei; i++){
        arr[i]= temp[i];
    }
    return inv_count;
}
int mergeSort(int arr[], int si, int ei, int temp[]){
    int mid;
    int inv_count=0;
    if(si < ei){
        mid= (si+ei) /2;

        inv_count += mergeSort(arr, si, mid, temp);
        inv_count += mergeSort(arr, mid+1, ei, temp);

        inv_count += _merge(arr, temp, si, mid+1, ei);
    }
    return inv_count;
}
int countingInversions(int arr[], int n){
    int temp[n];
    return mergeSort(arr, 0, n-1, temp);
}
int main(){
    int n;
    cout<< "Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<< "Enter array elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans= countingInversions(arr, n);
    cout<< "Number of inversions : "<<ans<<endl;
}
