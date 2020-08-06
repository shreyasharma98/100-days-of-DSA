#include<iostream>
#include<queue>
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
int numNodes(BinaryTreeNode<int>* root){
    if(root== NULL)
        return 0;
    return 1+ numNodes(root->left)+ numNodes(root->right);
}

bool isNodePresent(BinaryTreeNode<int>* root, int x){
    if(root== NULL)
        return false;
    if(root->data == x){
        return true;
    }
    bool ans= true;
    ans= isNodePresent(root->left, x) || isNodePresent(root->right, x);
    return ans;
}

int height(BinaryTreeNode<int>* root){
    if(root== NULL)
        return 0;
    return max(height(root->left), height(root->right)) +1;
}

void mirror(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    BinaryTreeNode<int>* temp;
    temp= root->left;
    root->left= root->right;
    root->right= temp;

    mirror(root->left);
    mirror(root->right);
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl;
    printLevelWise(root);
    cout<<"Number of Nodes is : "<<numNodes(root)<<endl;
    int x;
    cout<<"Enter the number u want to search : ";
    cin>>x;
    bool xPresent= isNodePresent(root, x);
    if(xPresent ==  true)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    cout<<"height of Binary Tree is  : "<<height(root)<<endl;
    mirror(root);
    printLevelWise(root);
}
