/*
Given a 2D array, find the maximum sum rectangle in it.
In other words find maximum sum over all rectangles in the matrix.
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/
#include <bits/stdc++.h>
using namespace std;
int kadane(int* arr, int* start, int* finish, int n){	//func returns maxSum in 1D array and
    		//store starting n ending indexes of maxSum subarray in start n finish ptrs
	int sum=0, maxSum= INT_MIN;
    *finish= -1;
    int st= 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum < 0){
            sum= 0;
            st= i+1;
        }
        else if(sum > maxSum){
            maxSum= sum;
            *start= st;
            *finish= i;
        }
    }
    if(*finish != -1)
        return maxSum;

    maxSum= arr[0];		//when all ele in array are negative
    *start= *finish= 0;
    for(int i=0; i<n; i++){
        if(arr[i] >maxSum){
            maxSum= arr[i];
            *start= *finish= i;
        }
    }
    return maxSum;
}

int maxSumRect(int **arr, int row, int col){
    int maxSum= INT_MIN;
    int finalRight, finalLeft, finalTop, finalBottom, sum, start, finish;
    int temp[row];
    for(int left=0; left<col; left++){
        memset(temp, 0, sizeof(temp));  //initializing all values of temp to 0
        for(int right= left; right<col; right++){	//right starts from left n goes till the end
            for(int i=0; i<row; i++){		//now iteratinf over the rows after fixing left n right
                temp[i] += arr[i][right];		//adding arr values to temp[i]
            }
            sum= kadane(temp, &start, &finish, row);		//kadane sets values of start and finish
            							//sum is sum of rectangle btwn start to left and finish to right
            							//i.e max sum w boundaries left n right
            if(sum > maxSum){
                maxSum= sum;
                finalLeft= left;
                finalRight= right;
                finalTop= start;
                finalBottom= finish;
            }
        }
    }
    return maxSum;
}

int main()
{
    int row, col;
    cin>>row>>col;
    int **arr= new int*[row];
    for(int i=0; i<row; i++){
        arr[i]= new int[col];
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }
    int ans= maxSumRect(arr, row, col);
    cout<<ans<<endl;
    return 0;
}
