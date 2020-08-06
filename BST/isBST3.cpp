//Given a binary tree with N number of nodes, check if that input tree is BST or not.
//If yes, return true, return false otherwise.
//Duplicate elements should be in right subtree.
//O(n)
#include<climits>
#include "binaryTree.h"

bool isBST3_helper(BinaryTreeNode<int>* root, int mini, int maxi){
    if(root == NULL)
        return true;
    if(root->data < mini || root->data > maxi)
        return false;

    bool isLeft= isBST3_helper(root->left, mini, root->data);
    bool isRight= isBST3_helper(root->right, root->data, maxi);

    return isLeft && isRight;
}
bool isBST3(BinaryTreeNode<int>* root){
    if(root== NULL)
        return true;
    return isBST3_helper(root, INT_MIN, INT_MAX);
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    bool output= isBST3(root);
    if(output == true)
        cout<<endl<< "YES"<<endl;
    else
        cout<<endl<< "NO"<<endl;
}
