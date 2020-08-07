#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> removeDup(int* arr, int size){
    vector<int> output;
    unordered_map<int, bool> seen;
    for(int i=0; i<size; i++){
        if(seen.count(arr[i]) > 0)
            continue;
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}
int main(){
    int n;
    cout<< "Enter the size of the array : ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> ans= removeDup(arr, n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<< " ";
    }
    return 0;
}
