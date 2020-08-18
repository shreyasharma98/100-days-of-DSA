//Implement a function to return total number of nodes in subtree if tree2 is a subtree of tree1
//else return 0
//10 4 6 -1 30 -1 -1 -1 -1
// 26 10 3 4 6 -1  3 -1 30 -1 -1 -1 -1 -1 -1
#include "binaryTree.h"

bool areIdentical(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    return (root1->data == root2->data && areIdentical(root1->left, root2->left)&& areIdentical(root1->right, root2->right));
}
bool isSubtree(BinaryTreeNode<int>* T, BinaryTreeNode<int>* S){
    if(S== NULL)
        return false;
    if(T== NULL)
        return false;
    if(areIdentical(T,S))
        return true;
    return isSubtree(T->left, S) || isSubtree(T->right, S);
}
int main(){
    BinaryTreeNode<int>* root1= takeInput();
    BinaryTreeNode<int>* root2= takeInput();
    bool ans= isSubtree(root1, root2);
    if(ans == true){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }
    return 0;
}
