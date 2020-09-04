/*
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”
Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”
Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’.
I think you would be able to figure out the correct decoding.
And why would you send me the word ‘BEAN’ anyway?”
Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings
and with that many you would find at least two different ones that would make sense.”
Alice: “How many different decodings?”
Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Sample Input:
25114
1111111111
3333333333
0
Sample Output:
6
89
1
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int n;
    while(true){
        cin>>str;
        if(str == "0")
            break;
        n= str.size();
        int dp[n+1];
        for(int i=0; i<n+1; i++)
            dp[i]= 0;
        dp[0]= 1;
        dp[1]= 1;
        for(int i=2; i<=n; i++){
            int num= ((str[i-2] - '0') *10)+ str[i-1] - '0';
            if(str[i-1] != '0')
                dp[i]= dp[i-1];
            if(num >=10 && num <= 26)
                dp[i] += dp[i-2];
            dp[i]= dp[i] % 1000000007;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
