//Given a Binary Search Tree and two integers k1 and k2,
//find and print the elements which are in range k1 and k2 (both inclusive).
//Print the elements in increasing order.
#include "binaryTree.h"
void elementsInRange(BinaryTreeNode<int>* root, int k1, int k2){
    if(root == NULL)
        return;
    if(root->data > k1)
        elementsInRange(root->left, k1, k2);
    if(root->data >= k1 && root->data <= k2){
        cout<<root->data<<" ";
    }
    if(root->data < k2)
        elementsInRange(root->right, k1, k2);
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    int k1, k2;
    cout<<endl<< "Enter k1 & k2 : ";
    cin>>k1>>k2;
    elementsInRange(root, k1, k2);
}
