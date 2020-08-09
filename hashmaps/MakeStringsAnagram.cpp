//Given two strings S1 and S2, find and return the minimum number of deletions to be made (total count of deletions in both strings) in order to make the strings anagram.
//Anagram of a string is a string which is its permutation.
//For example "bbaa" and "abab" are anagrams of each other but "bbaa" and "aaab" are not.
#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

int makeAnagram(char str1[], char str2[]){
    int del=0;
    unordered_map<char, int> map1;
    unordered_map<char, int> map2;
    for(int i=0; i<strlen(str1); i++){
        map1[str1[i]]++;
    }
    for(int i=0; i<strlen(str2); i++){
        map2[str2[i]]++;
    }
    for(int i=0; i<strlen(str1); i++){
        if(map2.count(str1[i])== 0){
            del++;
            map2.erase(str1[i]);
        }
        else {
            if(map1[str1[i]] > map2[str1[i]]){
                while(map1[str1[i]]!= map2[str1[i]]){
                    del++;
                    map1[str1[i]]--;
                }
            }
            else if(map2[str1[i]] > map1[str1[i]]){
                while(map1[str1[i]]!= map2[str1[i]]){
                    del++;
                    map2[str1[i]]--;
                }
            }
        }
    }
    for(int i=0; i<strlen(str2); i++){
        if(map2.count(str2[i])== 0){
            del++;
            map2.erase(str1[i]);
        }
        else {
            if(map1[str2[i]] > map2[str2[i]]){
                while(map1[str2[i]]!= map2[str2[i]]){
                    del++;
                    map1[str2[i]]--;
                }
            }
            else if(map2[str2[i]] > map1[str2[i]]){
                while(map1[str2[i]]!= map2[str2[i]]){
                    del++;
                    map2[str2[i]]--;
                }
            }
        }
    }
    return del;
}
int main(){
    char str1[10010], str2[10010];
    cout<< "Enter string 1 : ";
    cin>>str1;
    cout<< "Enter string 2 : ";
    cin>>str2;

    cout << makeAnagram(str1,str2) << endl;
}
