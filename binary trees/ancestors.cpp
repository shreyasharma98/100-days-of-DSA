//Given a binary tree with N number of nodes and a node K
//find and return a list of all ancestors of the given node K.
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
vector<int> ans,v;
void helper(BinaryTreeNode<int> *root, int k){
    if(root==NULL)
        return;
    if(root->data== k){
    	ans= v;
    }
    v.push_back(root->data);
    if(root->left)
        helper(root->left, k);
    if(root->right)
        helper(root->right, k);
    v.pop_back();
}
vector<int> ancestors(BinaryTreeNode<int> *root, int k) {
    /* Don't write main().
     * Don't read input, they are passed as function arguments.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    helper(root, k);
    return ans;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin>>k;
    vector<int> ans= ancestors(root, k);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
}
