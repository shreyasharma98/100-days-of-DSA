//Given a string, you need to remove all the duplicates.
//That means, the output string should contain each character only once.
//The respective order of characters should remain same.
#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

char* uniqueChar(char* str){
    char* ans= new char[strlen(str)+1];
    unordered_map<char, int> charMap;
    for(int i=0; i<strlen(str); i++){
        charMap[str[i]]++;
    }
    int j=0;
    for(int i=0; i<strlen(str); i++){
        if(charMap[str[i]]> 0){
            ans[j]= str[i];
            charMap[str[i]]= 0;
            j++;
        }
    }
    ans[j]= '\0';
    return ans;
}
int main(){
    char str[1000000];
    cin>>str;
    cout<< uniqueChar(str)<<endl;
}
