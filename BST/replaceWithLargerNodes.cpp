//Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it.
//You need to include the current node's data also.
//That is, if in given BST there is a node with data 5,
//you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.
//You don't need to return or print, just change the data of each node.
#include "binaryTree.h"
int replace_helper(BinaryTreeNode<int>* root, int &sum){
    if(root== NULL)
        return -1;
    replace_helper(root->right, sum);
    sum= sum+root->data;
    root->data = sum;
    replace_helper(root->left, sum);
    return sum;
}
void replaceWithLargerNodeSum(BinaryTreeNode<int>* root){
    int sum= 0;
    replace_helper(root, sum);
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl;
    replaceWithLargerNodeSum(root);
    printLevelOrderTraversal(root);
}
