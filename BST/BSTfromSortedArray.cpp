//Given a sorted integer array A of size n which contains all unique elements.
//You need to construct a balanced BST from this input array.
//Return the root of constructed BST.
//If array size is even, take first mid as root.
#include "binaryTree.h"
BinaryTreeNode<int>* constructTree(int *arr, int si, int ei){
    if(si > ei)
        return NULL;
    if(si == ei){
        BinaryTreeNode<int>* root= new BinaryTreeNode<int>(arr[si]);
        return root;
    }
    int mid= (si + ei)/2;
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(arr[mid]);
    BinaryTreeNode<int>* leftTree= constructTree(arr, si, mid-1);
    BinaryTreeNode<int>* rightTree= constructTree(arr, mid+1, ei);
    root->left= leftTree;
    root->right= rightTree;
    return root;
}
BinaryTreeNode<int>* BSTfromSortedArray(int *arr, int n){
    return constructTree(arr, 0 , n-1);
}
void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

int main(){
    cout<< "Enter the size of the array : ";
    int n;
    cin>>n;
    int arr[n];
    cout<<endl<< "Enter the sorted Array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    BinaryTreeNode<int>* root= BSTfromSortedArray(arr,n);
    cout<<endl<< "Preorder of the BST constructed from the sorted array is : ";
    preOrder(root);
}
