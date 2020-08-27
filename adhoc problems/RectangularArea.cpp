/*
CodingNinjas has given you N rectangles, which are centered in the center of the Cartesian coordinate system
and their sides are parallel to the coordinate axis.
Each rectangle is uniquely with its width and height.
Navdeep has colored each rectangle in a certain color and now wants to know the area of the colored part.
INPUT :
3
8 2
4 4
2 6
OUTPUT :
28
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;
    int* height= new int[5000000+2]();
    int max_x= 0;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        if(height[x/2] < y){
            height[x/2]= y;
        }
        if((x/2)> max_x){
            max_x= x/2;
        }
    }
    long area= 0;
    for(int i= max_x; i>0; i--){
        if(height[i] < height[i+1]){
            height[i]= height[i+1];
        }
        area += height[i];
    }
    cout<< 2*area << endl;
    return 0;
}
