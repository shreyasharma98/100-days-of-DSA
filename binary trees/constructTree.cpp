//Given Preorder and Inorder traversal of a binary tree
// create the binary tree associated with the traversals.
//You just need to construct the tree and return the root.
//PREORDER : root, left, right
//INORDER : left, root, right

#include "binaryTree.h"
BinaryTreeNode<int>* buildTree_helper(int* preorder, int* inorder, int preS, int preE, int inS, int inE){
    if(preS > preE)
        return NULL;
    int rootData= preorder[preS];
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    int inLS= inS;
    int preLS= preS +1;
    int rootIndex;
    for(int i= inS; i<=inE; i++){
        if(inorder[i]== rootData){
            rootIndex= i;
            break;
        }
    }
    int inLE= rootIndex -1;
    int preLE= inLE- inS + preLS;
    int inRS= rootIndex +1;
    int inRE= inE;
    int preRS= preLE +1;
    int preRE= preE;
    BinaryTreeNode<int>* leftT= buildTree_helper(preorder, inorder, preLS, preLE, inLS, inLE);
    BinaryTreeNode<int>* rightT= buildTree_helper(preorder, inorder, preRS, preRE, inRS, inRE);
    root->left= leftT;
    root->right= rightT;
    return root;


}
BinaryTreeNode<int>* buildTree(int* preorder, int preLength, int* inorder, int inLength){
    int preS=0;
    int preE= preLength -1;
    int inS= 0;
    int inE= inLength -1;
    BinaryTreeNode<int>* ans= buildTree_helper(preorder, inorder, preS, preE, inS, inE);
    return ans;
}
int main(){
    int n;
    cout<< "Enter the total number of nodes in BT : ";
    cin>>n;
    cout<< "Enter the preorder traversal : ";
    int pre[n];
    for(int i=0; i<n; i++){
        cin>>pre[i];
    }
    cout<< "Enter the inorder traversal : ";
    int in[n];
    for(int i=0; i<n; i++){
        cin>>in[i];
    }
    BinaryTreeNode<int>* ans= buildTree(pre, n, in, n);
    printLevelWise(ans);
}
