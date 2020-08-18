/*
Once detective Saikat was solving a murder case.
While going to the crime scene he took the stairs and saw that a number is written on every stair.
He found it suspicious and decides to remember all the numbers that he has seen till now.
While remembering the numbers he found that he can find some pattern in those numbers.
So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number.
Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll merge(int *arr1, int size1, int* arr2, int size2){
    int currmaxindex= size1;
    ll currans= 0;
    ll finalans= 0;
    for(int i=0; i<size1; i++){
        if(arr1[i] >= arr2[0]){
            currmaxindex= i;
            break;
        }
        else{
            currans += arr1[i];
        }
    }
    finalans= currans;
    for(int i=1; i<size2; i++){
        ll localcurrans= currans;
        while(arr2[i]> arr1[currmaxindex] && currmaxindex< size1){
            localcurrans += arr1[currmaxindex];
            currmaxindex++;
        }
        currans= localcurrans;
        finalans += localcurrans;
    }
    return finalans;
}

ll mergesort(int* arr, int si, int ei){
    if(si>= ei)
        return 0;
    int mid= (si+ei)/2;
    int *arr1= new int [mid-si+1];
    int *arr2= new int [ei-mid];
    for(int i=si, k=0; i<=mid; i++, k++){
        arr1[k]= arr[i];
    }
    for(int i=mid+1, k=0; i<=ei; i++, k++){
        arr2[k]= arr[i];
    }
    sort(arr1, arr1+mid-si+1);
    sort(arr2, arr2+ei-mid);
    ll ans= merge(arr1, mid-si+1, arr2, ei-mid);
    delete [] arr1;
    delete [] arr2;
    ans+= mergesort(arr, si, mid) + mergesort(arr, mid+1, ei);
    return ans;
}

int main()
{
    int t;
    int i , n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(i = 0 ; i < n ; i++)
            cin>>arr[i];

        cout<<mergesort(arr, 0 , n - 1)<<endl;
    }

    return 0;
}
