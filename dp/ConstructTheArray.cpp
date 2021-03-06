/*
Your goal is to find the number of ways to construct an array such that consecutive positions contain different values.
Specifically, we want to construct an array with n elements such that each element between 1 and k inclusive.
We also want the first and last elements of the array to be 1 and x.
Given n, k and x find the number of ways to construct such an array. Since the answer may be large, only find it modulo 10^9 + 7.
input :
n=4, k=3, x=2
output :
3
explanation :
1 2 1 2
1 2 3 2
1 3 1 2
*/

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
vector<string> split_string(string);

// Complete the countArray function below.
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    long oneCount= 1;
    long noneOneCount= 0;

    for(int i=1; i<n; i++){
        long prevOneCount= oneCount;
        oneCount= (noneOneCount*(k-1))%MOD;
        noneOneCount= (prevOneCount + ((noneOneCount)*(k-2))%MOD)%MOD;
    }
    if(x== 1){
        return oneCount;
    }
    else{
        return noneOneCount;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nkx_temp;
    getline(cin, nkx_temp);

    vector<string> nkx = split_string(nkx_temp);

    int n = stoi(nkx[0]);

    int k = stoi(nkx[1]);

    int x = stoi(nkx[2]);

    long answer = countArray(n, k, x);

    fout << answer << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
