/* During the lesson small girl Alyona works with one famous spreadsheet computer program and learns how to edit tables.
Now she has a table filled with integers. The table consists of n rows and m columns.
By ai,j we will denote the integer located at the i-th row and the j-th column.
We say that the table is sorted in non-decreasing order in the column j if ai,j≤ai+1,j for all i from 1 to n-1.
Teacher gave Alyona k tasks. For each of the tasks two integers l and r are given and Alyona has to answer the following question:
if one keeps the rows from l to r inclusive and deletes all others, will the table be sorted in non-decreasing order in at least one column?
Formally, does there exist such j that ai,j≤ai+1,j for all i from l to r-1 inclusive.
Alyona is too small to deal with this task and asks you to help!
Sample Input
5 4
1 2 3 5
3 1 3 2
4 5 2 3
5 5 3 2
4 4 3 4
6
1 1
2 5
4 5
3 5
1 3
1 5
Sample Output
Yes
No
Yes
Yes
Yes
No
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m; cin>>n>>m;
    int input[2][m], output[2][m], ans[n+1];
    ans[0]=0;
    int first = 1, second =0;
    for(int i=1; i<=n; i++){
        int min = INT_MAX;
        swap(first, second);
        for(int j=0; j<m; j++){
            cin>> input[second][j];
            if(input[second][j]>= input[first][j]){
                output[second][j] = output[first][j];
            }else{
                output[second][j] = i;
            }
            if(output[second][j]<min){
                min= output[second][j];
            }
        }
        ans[i] = min;
    }
    int k; cin>>k;
    for(int i=0; i<k; i++){
        int l,r; cin>>l>>r;
        if(ans[r]>l){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
