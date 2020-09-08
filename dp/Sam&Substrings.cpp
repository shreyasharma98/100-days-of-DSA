/*
Samantha and Sam are playing a numbers game. Given a number as a string, no leading zeros,
determine the sum of all integer values of substrings of the string. For example, if the string is 42 , the substrings are 4, 2 and 42. Their sum is 46.
Given an integer as a string, sum all of its substrings cast as integers. As the number may become large, return the value modulo 10^9 + 7;
input :
16
output :
23
*/
#include <bits/stdc++.h>

using namespace std;
#define mod 1000000007
// Complete the substrings function below.
int substrings(string s) {

    long long totalSum= s[0]- '0';
    long long lastValue= s[0]- '0';
    for(int i=1; i<s.length(); i++){
        lastValue= lastValue*10 + (s[i]- '0')*(i+1);
        lastValue=lastValue% mod;
        totalSum= (totalSum + lastValue)% mod;
    }
    return totalSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
