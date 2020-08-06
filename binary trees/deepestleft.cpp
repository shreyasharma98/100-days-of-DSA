//Given a binary tree, find and return its deepest leaf node which is left child of some node.
//If there are multiple deepest left leaf nodes, return the node with maximum value.
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
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

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
int depth= 0;
int value=0;
void dfs(BinaryTreeNode<int>* root, int lvl, int isLeft){
    if(root== NULL)
        return;
    dfs(root->left, lvl+1, 1);
    dfs(root->right, lvl+1, 0);
    if(isLeft){
        if(depth < lvl){
            depth= lvl;
            value= root->data;
        }
        else if(depth == lvl){
            value= max(value, root->data);
        }
    }
}
int solve(BinaryTreeNode<int>* root){
    	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Return output and don't print it.
	* Taking input and printing output is handled automatically.
	*/
	dfs(root, 1, 0);
    return value;
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout<<solve(root);
}
