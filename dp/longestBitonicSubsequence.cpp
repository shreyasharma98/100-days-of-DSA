/*
You are given an array of positive integers as input.
Write a code to return the length of the largest such subsequence in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence.
A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
*/
#include<iostream>
using namespace std;

int longestBitonicSubarray(int *input, int n) {

    	int* lis= new int[n];	//L to R
        int* lds= new int[n];	//R to L

     	for(int i=0; i<n; i++){
            lis[i]= 1;
            lds[i]= 1;
        }
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(input[j] < input[i] && lis[i] < lis[j] + 1)
                    lis[i]= lis[j]+ 1;
            }
        }

        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(input[j] < input[i] && lds[i] < lds[j] + 1)
                    lds[i]= lds[j]+ 1;
            }
        }

        int max= 0;
        for(int i=0; i<n; i++){
            if(max < (lis[i] + lds[i] -1))
                max= lis[i] + lds[i] -1;
        }
        return max;
 	}
int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}

