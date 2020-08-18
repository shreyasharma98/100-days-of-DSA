/*Chef is a cook and he has recently opened a restaurant.

The restaurant is open during N
time intervals [L1,R1),[L2,R2),…,[LN,RN). No two of these intervals overlap — formally, for each valid i, j such that i≠j, either Ri<Lj or Rj<Li

.

M
people (numbered 1 through M) are planning to eat at the restaurant; let's denote the time when the i-th person arrives by Pi

. If the restaurant is open at that time, this person does not have to wait, but if it is closed, this person will wait until it is open.
Note that if this person arrives at an exact time when the restaurant is closing, they have to wait for the next opening time.

For each person, calculate how long they have to wait (possibly 0
time), or determine that they will wait forever for the restaurant to open.
Example Input
1
4 5
5 7
9 10
2 3
20 30
5
6
7
35
1
Example Output
0
0
2
-1
1
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<pair<int, int>> intervals;
        for(int i=0; i<n; i++){
            int start, end;
            cin>>start>>end;
            intervals.push_back(make_pair(start, end));
        }
        sort(intervals.begin(), intervals.end());
        while(m--){
            int curr_time;
            cin>>curr_time;
            int position= lower_bound(intervals.begin(), intervals.end(), make_pair(curr_time, 0)) - intervals.begin();
            //when curr_time matches w 0th position
            if(position == 0){
                int ans= intervals[0].first - curr_time;
                cout<<ans<<endl;
            }
            else{
                int ans= -1;
                //comparing w just before this position
                if(intervals[position - 1].second > curr_time){
                    ans= 0;
                }else if(position < intervals.size()){
                    //position lies in intervals
                    ans= intervals[position].first - curr_time;
                }
                //if ans== -1 then position out of bound
                cout<<ans<<endl;
            }
        }
    }
}
