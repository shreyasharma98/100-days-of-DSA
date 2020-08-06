//Given Postorder and Inorder traversal of a binary tree
// create the binary tree associated with the traversals.
//You just need to construct the tree and return the root.
//POSTORDER : left, right, root
//INORDER : left, root, right

#include "binaryTree.h"
BinaryTreeNode<int>* buildTree_helper(int* postorder, int* inorder, int postS, int postE, int inS, int inE){
    if(postS > postE)
        return NULL;
    int rootData= postorder[postE];
    BinaryTreeNode<int>* root= new BinaryTreeNode<int>(rootData);
    int inLS= inS;
    int postLS= postS;
    int rootIndex;
    for(int i= inS; i<=inE; i++){
        if(inorder[i]== rootData){
            rootIndex= i;
            break;
        }
    }
    int inLE= rootIndex -1;
    int postLE= inLE- inS + postLS;
    int postRS= postLE +1;
    int postRE= postE -1;
    int inRS= rootIndex +1;
    int inRE= inE;

    BinaryTreeNode<int>* leftT= buildTree_helper(postorder, inorder, postLS, postLE, inLS, inLE);
    BinaryTreeNode<int>* rightT= buildTree_helper(postorder, inorder, postRS, postRE, inRS, inRE);
    root->left= leftT;
    root->right= rightT;
    return root;


}
BinaryTreeNode<int>* buildTree(int* postorder, int postLength, int* inorder, int inLength){
    int postS=0;
    int postE= postLength -1;
    int inS= 0;
    int inE= inLength -1;
    BinaryTreeNode<int>* ans= buildTree_helper(postorder, inorder, postS, postE, inS, inE);
    return ans;
}
int main(){
    int n;
    cout<< "Enter the total number of nodes in BT : ";
    cin>>n;
    cout<< "Enter the postorder traversal : ";
    int post[n];
    for(int i=0; i<n; i++){
        cin>>post[i];
    }
    cout<< "Enter the inorder traversal : ";
    int in[n];
    for(int i=0; i<n; i++){
        cin>>in[i];
    }
    BinaryTreeNode<int>* ans= buildTree(post, n, in, n);
    printLevelWise(ans);
}
