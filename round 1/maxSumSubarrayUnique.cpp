/* we are given an array with positive numbers,
 we have to find Subarray with maximum sum with unique elements.
 VARIATION OF KADANE'S ALGORITHM */

 #include<bits/stdc++.h>
 using namespace std;

 int solve(vector<int> &v){
    int cs, ce, fs, fe;
    cs=ce=fs=fe=0;
    int ans= INT_MIN;
    int sum= 0;
    unordered_set<int> set1;

    while(ce< v.size()){
        if(set1.find(v[ce]) != set1.end()){     //if element found
                while(v[cs-1] != v[ce]){ //start from cs until that element is found
                    sum-= v[cs];
                    set1.erase(v[cs]);
                    cs++;
                }
        }
        sum += v[ce];
        set1.insert(v[ce]);
        if(sum >ans){
            fs= cs;
            fe= ce;
            ans= sum;
        }
        ce++;
    }
    cout<<"subarray is : ";
    for(int i= fs; i<= fe; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<"max sum: "<<ans<<endl;
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    solve(v);
    return 0;
}
