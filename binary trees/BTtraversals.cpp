//Tree traversals both recursively and iteratively
#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
template<typename T>

class BinaryTreeNode{
public:
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

	BinaryTreeNode(T data){
		this->data= data;
		left= NULL;
		right=NULL;
	}
	~BinaryTreeNode(){
		delete left;
		delete right;
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
void printLevelWise(BinaryTreeNode<int>* root){
	if(root == NULL)
		return;
	queue<BinaryTreeNode<int>*> pendingNode;
	pendingNode.push(root);
	while(pendingNode.size()!= 0){
		BinaryTreeNode<int>* front= pendingNode.front();
		cout<<front->data<<":";
		pendingNode.pop();
		if(front->left != NULL){
			cout<<" L:"<<front->left->data<<" ";
			pendingNode.push(front->left);
		}
		else
			cout<<" L: -1 ";
		if(front->right != NULL){
			cout<<" R:"<<front->right->data<<endl;
			pendingNode.push(front->right);
		}
		else
			cout<<" R: -1 "<<endl;
	}
}
void Rinorder(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    Rinorder(root->left);
    cout<<root->data<<" ";
    Rinorder(root->right);
}
void Rpreorder(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    Rpreorder(root->left);
    Rpreorder(root->right);
}
void Rpostorder(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    Rpostorder(root->left);
    Rpostorder(root->right);
    cout<<root->data<<" ";
}

void inorder(BinaryTreeNode<int>* root){
    stack<BinaryTreeNode<int>*> s;
    BinaryTreeNode<int>* curr= root;
    while(curr != NULL || s.empty() == false){
        while(curr!= NULL){
            s.push(curr);
            curr=  curr->left;
        }
        curr= s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr= curr->right;
    }
}

void preorder(BinaryTreeNode<int>* root){
    if(root== NULL)
        return;
    stack<BinaryTreeNode<int>*> s;
    BinaryTreeNode<int>* curr= root;
    while(curr != NULL || s.empty() == false){
        while(curr!= NULL){
            cout<<curr->data<<" ";
            s.push(curr->right);
            curr=  curr->left;
        }
        if(s.empty()== false){
            curr= s.top();
            s.pop();
        }
    }
}
//POSTORDER
//1. Push root to first stack.
//2. Loop while first stack is not empty
//   2.1 Pop a node from first stack and push it to second stack
//   2.2 Push left and right children of the popped node to first stack
//3. Print contents of second stack
void postorder(BinaryTreeNode<int>* root){

    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    BinaryTreeNode<int>* temp;
    while(!s1.empty()){
        temp= s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left)
            s1.push(temp->left);
        if(temp->right)
            s1.push(temp->right);
    }
    while(!s2.empty()){
        temp= s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }
}
int main(){
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl;
    printLevelWise(root);
    cout<<"ITERATIVE TRAVERSALS----------------------------"<<endl;
    cout<<"INORDER TRAVERSAL : ";
    inorder(root);
    cout<<endl<<"PREORDER TRAVERSAL : ";
    preorder(root);
    cout<<endl<<"POSTORDER TRAVERSAL : ";
    postorder(root);
    cout<<endl;
    cout<<"RECURSIVE TRAVERSALS----------------------------"<<endl;
    cout<<"INORDER TRAVERSAL : ";
    Rinorder(root);
    cout<<endl<<"PREORDER TRAVERSAL : ";
    Rpreorder(root);
    cout<<endl<<"POSTORDER TRAVERSAL : ";
    Rpostorder(root);
    return 0;
}

