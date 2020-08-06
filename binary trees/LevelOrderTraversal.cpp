//Given a binary tree, print the level order traversal.
//Make sure each level start in new line.
#include<queue>
#include<iostream>
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
void printLevelOrderTraversal(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    BinaryTreeNode<int>* curr;
    while(q.size()!=0){
        curr= q.front();
        q.pop();
        if(curr != NULL){
            cout<<curr->data<<" ";
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        else{
            if(q.size() != 0){
                cout<<endl;
                q.push(NULL);
            }
        }
    }
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl;
    printLevelOrderTraversal(root);
    return 0;
}
