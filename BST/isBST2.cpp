//Given a binary tree with N number of nodes, check if that input tree is BST or not.
//If yes, return true, return false otherwise.
//Duplicate elements should be in right subtree.
//O(n)
#include<climits>
#include "binaryTree.h"

class isBSTReturn{
public:
    bool BST;
    int minimum;
    int maximum;
};
isBSTReturn isBST2(BinaryTreeNode<int>* root){
    if(root== NULL){
        isBSTReturn ans;
        ans.BST= true;
        ans.minimum= INT_MAX;
        ans.maximum= INT_MIN;
        return ans;
    }
    isBSTReturn leftAns= isBST2(root->left);
    isBSTReturn rightAns= isBST2(root->right);
    int mini= min(root->data, min(leftAns.minimum, rightAns.minimum));
    int maxi= max(root->data, max(leftAns.maximum, rightAns.maximum));
    bool finalBST= (root->data > leftAns.maximum)&& (root->data <= rightAns.minimum)&& leftAns.BST && rightAns.BST;
    isBSTReturn output;
    output.BST= finalBST;
    output.minimum= mini;
    output.maximum= maxi;
    return output;
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    isBSTReturn output= isBST2(root);
    if(output.BST == true)
        cout<<endl<< "YES"<<endl;
    else
        cout<<endl<< "NO"<<endl;
}
