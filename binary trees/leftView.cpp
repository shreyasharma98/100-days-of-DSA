//Given a Binary Tree, print left view of it.
//Left view of a Binary Tree is set of nodes visible when tree is visited from left side.
//The left view contains all nodes that are first nodes in their levels.
#include "binaryTree.h"
void leftView_helper(BinaryTreeNode<int>* root, int lvl, int* maxLevel){
    if(root == NULL)
        return;
    if(lvl > *maxLevel){
        cout<<root->data<< " ";
        *maxLevel= lvl;
    }
    leftView_helper(root->left, lvl+1, maxLevel);
    leftView_helper(root->right, lvl+1, maxLevel);
}

void leftView(BinaryTreeNode<int>* root){
    int maxLevel=0;
    return leftView_helper(root, 1, &maxLevel);         //note the &
}

int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl<<"Left View of the BT : ";
    leftView(root);
}
