//Given two random integer arrays, print their intersection.
//That is, print all the elements that are present in both the given arrays.
//Input arrays can contain duplicate elements.
//time- O(m+n)
#include<iostream>
#include<unordered_map>
using namespace std;

void intersection(int arr1[], int arr2[], int n1, int n2){
    unordered_map<int, int> present;
    if(n1 > n2){
        for(int i=0; i<n1; i++){
            present[arr1[i]]++;
        }
        for(int i=0; i<n2; i++){
            if(present.count(arr2[i])> 0)
                cout<<arr2[i]<<" ";
            present[arr2[i]]--;
            if(present.count(arr2[i])== 0)
                present.erase(arr2[i]);
        }
    }
    else{
        for(int i=0; i<n2; i++){
            present[arr2[i]]++;
        }
        for(int i=0; i<n1; i++){
            if(present.count(arr1[i])> 0)
                cout<<arr1[i]<<" ";
            present[arr1[i]]--;
            if(present.count(arr1[i])== 0)
                present.erase(arr1[i]);
        }
    }
}
int main() {

	int size1,size2;
    cout<< "Enter the size of first array : ";
	cin>>size1;
	int *input1=new int[1+size1];
    cout<< "Enter array elements : ";
	for(int i=0;i<size1;i++)
		cin>>input1[i];
    cout<< "Enter the size of second array : ";
	cin>>size2;
	int *input2=new int[1+size2];
    cout<< "Enter array elements : ";
	for(int i=0;i<size2;i++)
		cin>>input2[i];


	intersection(input1,input2,size1,size2);


	return 0;
}
