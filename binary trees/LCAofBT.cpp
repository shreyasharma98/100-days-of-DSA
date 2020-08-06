//Given a binary tree and two nodes
//find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree.
#include "binaryTree.h"

int LCAofBT(BinaryTreeNode<int>* root, int k1, int k2){
    if(root== NULL)
        return -1;
    if(k1== root->data || k2== root->data){
        return root->data;
    }
    int lAns= LCAofBT(root->left, k1, k2);
    int rAns= LCAofBT(root->right, k1, k2);
    if(lAns == -1)
        return rAns;
    else if(rAns == -1)
        return lAns;
    else if(lAns == -1 && rAns == -1)
        return -1;
    else
        return root->data;
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    int k1, k2;
    cout<<endl<< "Enter the 2 nodes you want to find LCA of : ";
    cin>>k1>>k2;
    int ans= LCAofBT(root, k1, k2);
    cout<<ans;
}
