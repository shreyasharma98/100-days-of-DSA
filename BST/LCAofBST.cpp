//Given a binary search tree and two nodes,
// find LCA(Lowest Common Ancestor) of the given two nodes in the BST.
#include "binaryTree.h"

int LCAofBST(BinaryTreeNode<int>* root, int k1, int k2){
    if(root== NULL)
        return -1;
    if(k1== root->data || k2== root->data){
        return root->data;
    }
    if(k1 < root->data && k2 < root->data){
        int l= LCAofBST(root->left, k1, k2);
        return l;
    }
    else if(k1 > root->data && k2 > root->data){
        int r= LCAofBST(root->right, k1, k2);
        return r;
    }
    else
        return root->data;
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl<< "Enter the two numbers you want to find LCA of :";
    int k1, k2;
    cin>>k1>>k2;
    int ans= LCAofBST(root, k1, k2);
    cout<<ans;
}
