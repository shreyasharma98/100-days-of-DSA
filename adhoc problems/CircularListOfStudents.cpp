/*
You are given a circular list of students as follows:
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11
This list is circular, means that 11 will follow 0 again. You will be given the student number ‘i’ and some position ‘p’.
You will have to tell that if the list will start from (i+1)th student, then which student will be at pth position.
Sample Input:
2
2 3
5 8
Sample Output:
5
1
*/
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
	int data;
    node* next;
    node(int data){
        this->data= data;
        this->next= NULL;
    }
};
int main()
{
    node* head= NULL;
    node* tail= NULL;
    int i=0;
    while(i<= 11){
        node* newNode= new node(i);
        if(head== NULL){
            head= newNode;
            tail= newNode;
        }
        else{
        	tail->next= newNode;
            tail= tail->next;
        }
        i++;
    }
    tail->next= head;

    int t;
    cin>>t;
    while(t--){
        int i, p;
        cin>>i>>p;
        node* temp= head;
        int ctr= 0;
        while(ctr != i){
            temp= temp->next;
            ctr++;
        }
        ctr =0;
        while(ctr != p){
            temp= temp->next;
            ctr++;
        }
        cout<<temp->data<<endl;
    }
	return 0;
}

