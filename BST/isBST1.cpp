//Given a binary tree with N number of nodes, check if that input tree is BST or not.
//If yes, return true, return false otherwise.
//Duplicate elements should be in right subtree.
//O(n*h)
#include<climits>
#include "binaryTree.h"

int maximum(BinaryTreeNode<int>* root){
    if(root== NULL)
        return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
int minimum(BinaryTreeNode<int>* root){
    if(root == NULL)
        return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
bool isBST1(BinaryTreeNode<int>* root){
    if(root == NULL)
        return true;
    int leftMax= maximum(root->left);
    int rightMin= minimum(root->right);
    bool ans= (root->data > leftMax)&& (root->data <= rightMin) && isBST1(root->left) && isBST1(root->right);
    return ans;
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    bool output= isBST1(root);
    if(output == true)
        cout<<endl<< "YES"<<endl;
    else
        cout<<endl<< "NO"<<endl;
}
