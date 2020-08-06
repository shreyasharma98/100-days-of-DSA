//Given the binary Tree and two nodes say ‘p’ and ‘q’.
//Determine whether the two nodes are cousins of each other or not.
//Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.
#include "binaryTree.h"
bool isSibling(BinaryTreeNode<int>* root, int p, int q){
    if(root == NULL)
        return false;
    if(root->left != NULL && root->right != NULL){
        if(root->left->data==p && root->right->data==q)
            return true;
        else if(root->left->data== q && root->right->data== p)
            return true;
        else
            return isSibling(root->left, p, q) || isSibling(root->right, p, q);
    }
    if(root->left != NULL)
        return isSibling(root->left, p, q);
    else
        return isSibling(root->right, p, q);
}
int depth(BinaryTreeNode<int>* root, int n){
    if(root == NULL)
        return -1;
    if(root->data == n){
        return 0;
    }
    int left= depth(root->left, n);
    if(left != -1)
        return left +1;
    else{
        int right= depth(root->right, n);
        if(right != -1)
            return right +1;
        else
            return -1;
    }
}
bool isCousin(BinaryTreeNode<int>* root, int p, int q){
    if((depth(root,p)== depth(root,q)) && (!isSibling(root,p,q))){
        return true;
    }
    else
        return false;
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl<< "Enter p and q : ";
    int p,q;
    cin>>p>>q;
    bool ans= isCousin(root, p, q);
    if(ans== true)
        cout<<p<<" and "<<q<<"are cousins"<<endl;
    else
        cout<<p<<" and "<<q<<" are not cousins"<<endl;
    return 0;
}
