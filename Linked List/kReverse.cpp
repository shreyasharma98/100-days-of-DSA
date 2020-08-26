/*
Implement kReverse( int k ) in a linked list i.e.
you need to reverse first K elements then reverse next k elements and join the linked list and so on.
Indexing starts from 0. If less than k elements left in the last, you need to reverse them as well.
If k is greater than length of LL, reverse the complete LL.
You don't need to print the elements, just return the head of updated LL.
*/
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* next;
    node(int data){
        this->data= data;
        this->next= next;
    }
};
node* takeInput(){
    int data;
    cin>> data;
    node* head= NULL;
    node* tail= NULL;
    while(data != -1){
        node* newNode= new node(data);
        if(head == NULL){
            head= newNode;
            tail= newNode;
        }
        else{
            tail->next= newNode;
            tail= newNode;
        }
        cin>>data;
    }
    return head;
}
void print(node* head){
    node* temp= head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}

node* kReverse(node* head, int k){
    node* curr= head;
    node* prev= NULL;
    node* h2= NULL;
    int count= 0;
    while(curr != NULL && count < k){
        h2= curr->next;
        curr->next= prev;
        prev= curr;
        curr= h2;
        count++;
    }
    if(h2 != NULL)
        head->next= kReverse(h2, k);

    return prev;
}

int main(){
    node* head= takeInput();
    int k;
    cin>> k;
    node* ans= kReverse(head, k);
    print(ans);
    return 0;
}
