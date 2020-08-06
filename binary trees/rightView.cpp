//Given a binary tree. Print the Right View of Binary Tree.
//The Right view contains all nodes that are last nodes in their levels.
#include "binaryTree.h"
void rightView_helper(BinaryTreeNode<int>* root, int lvl, int* maxLevel){
    if(root == NULL)
        return;
    if(lvl > *maxLevel){
        cout<<root->data<< " ";
        *maxLevel= lvl;
    }
    rightView_helper(root->right, lvl+1, maxLevel);
    rightView_helper(root->left, lvl+1, maxLevel);
}

void rightView(BinaryTreeNode<int>* root){
    int maxLevel=0;
    return rightView_helper(root, 1, &maxLevel);         //note the &
}

int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl<<"Right View of the BT : ";
    rightView(root);
}
