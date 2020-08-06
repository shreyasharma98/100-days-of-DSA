//Calculate the angle between hour hand and minute hand.
//There can be two angles between hands, we need to print minimum of two.
//Also, we need to print floor of final result angle. For example, if the final angle is 10.61, we need to print 10.
#include<bits/stdc++.h>
using namespace std;

int clockAngle(double h, double m){
    if(h<0 || m<0 || h>12 || m>60){
        cout<< "Incorrect output"<<endl;
    }
    if(h == 12)
        h=0;
    if(m == 60){
        m=0;
        h+=1;
        if(h>12)
            h= h-12;
    }
    int hour_angle= 0.5 * (h*60 + m);
    int min_angle= 6*m;
    int angle= abs(hour_angle - min_angle);
    angle= min(360-angle, angle);

    return angle;
}
int main(){
    double h, m;
    cout<< "Enter the hours n minutes : ";
    cin>>h>>m;
    int ans= clockAngle(h, m);
    cout<<ans<<" degree";
    return 0;
}
