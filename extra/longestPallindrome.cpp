//Given a string, find the longest substring which is palindrome.
#include<bits/stdc++.h>
using namespace std;

int longestPallindrom(char* str){
    int maxLength= 1;
    int start= 0;
    int low, high;
    int len= strlen(str);
    for(int i=1; i<len; i++){
        low= i-1;
        high= i;
        while(low>= 0 && high< len && str[low]== str[high]){
            if(high- low+1 >maxLength){
                start= low;
                maxLength= high- low+1;
            }
            --low;
            ++high;
        }
        low= i-1;
        high= i+1;
        while(low>= 0 && high< len && str[low]== str[high]){
            if(high- low+1 >maxLength){
                start= low;
                maxLength= high- low+1;
            }
            --low;
            ++high;
        }
    }
    cout<< "Longest Palindromic substring is : ";
    for(int i=start; i<=start + maxLength-1; i++)
        cout<<str[i];
    return maxLength;
}
int main(){
    char str[100];
    cout<< "Enter the string : ";
    cin>>str;
    int ans= longestPallindrom(str);
    cout<<" of length : "<<ans<<endl;
}
