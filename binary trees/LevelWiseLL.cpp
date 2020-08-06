//Given a binary tree, write code to create a separate linked list for each level.
//You need to return the array which contains head of each level linked list.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode<int>* takeInput(){
	int rootData;
	cout<<"Enter root data : ";
	cin>>rootData;
	if(rootData == -1)
		return NULL;
	BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNode;
	pendingNode.push(root);
	while(pendingNode.size()!= 0){
		BinaryTreeNode<int>* front= pendingNode.front();
		pendingNode.pop();
		cout<<"Enter left child of "<<front->data<<" : ";
		int leftChildData;
		cin>>leftChildData;
		if(leftChildData!= -1){
			BinaryTreeNode<int>* child= new BinaryTreeNode<int>(leftChildData);
			front->left= child;
			pendingNode.push(child);
		}
		cout<<"Enter right child of "<<front->data<<" : ";
		int rightChildData;
		cin>>rightChildData;
		if(rightChildData!= -1){
			BinaryTreeNode<int>* child= new BinaryTreeNode<int>(rightChildData);
			front->right= child;
			pendingNode.push(child);
		}
	}
	return root;
}
vector<node<int>*> levelWiseLL(BinaryTreeNode<int>* root){
    vector<node<int>*> output;
    queue<BinaryTreeNode<int>*> q;
    BinaryTreeNode<int>* curr;
    node<int>* head= NULL;
    node<int>* tail= NULL;
    q.push(root);
    q.push(NULL);
    while(q.size()!= 0){
        curr= q.front();
        q.pop();
        if(curr != NULL){
            node<int>* newNode= new node<int>(curr->data);
            if(head == NULL){
                head= newNode;
                tail= newNode;
            }
            else{
                tail->next= newNode;
                tail= newNode;
            }
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        else{
            output.push_back(head);
            head= NULL;
            tail= NULL;
            if(q.empty())
                break;
            q.push(NULL);
        }
    }
    return output;
}
void print(node<int>* head){
    node<int>* temp= head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
    cout<<endl;
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl;
    vector<node<int>*> ans= levelWiseLL(root);
    for(int i=0; i<ans.size(); i++){
        print(ans[i]);
    }
}
