#include "binaryTree.h"
void nodesWithoutSibling(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    if(root->left != NULL && root->right == NULL)
        cout<<root->left->data<<endl;
    else if(root->left == NULL && root->right != NULL)
        cout<<root->right->data<<endl;
    nodesWithoutSibling(root->left);
    nodesWithoutSibling(root->right);
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl<< "Nodes without siblings are : ";
    nodesWithoutSibling(root);
    return 0;
}
