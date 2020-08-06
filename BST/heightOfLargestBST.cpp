//Given a Binary tree, find the largest BST subtree.
//That is, you need to find the BST with maximum height in the given binary tree.
#include "binaryTree.h"
#include<climits>
#include<algorithm>
class LargestBST{
public:
    int min;
    int max;
    bool isBST;
    int height;
};
LargestBST heightOfLargestBST(BinaryTreeNode<int>* root){
    if(root== NULL){
        LargestBST ans;
        ans.min= INT_MAX;
        ans.max= INT_MIN;
        ans.isBST= true;
        ans.height= 0;
        return ans;
    }
    if(root->left== NULL && root->right== NULL){
        LargestBST ans;
        ans.min= root->data;
        ans.max= root->data;
        ans.isBST= true;
        ans.height= 1;
        return ans;
    }
    LargestBST leftAns= heightOfLargestBST(root->left);
    LargestBST rightAns= heightOfLargestBST(root->right);
    LargestBST output;
    output.min= min(root->data, min(rightAns.min, leftAns.min));
    output.max= max(root->data, max(leftAns.max, rightAns.max));
    if(leftAns.isBST== true && rightAns.isBST== true && leftAns.max <root->data && rightAns.min >root->data){
        output.isBST= true;
        output.height= max(leftAns.height, rightAns.height) +1;
    }
    else{
        output.isBST= false;
        output.height= max(leftAns.height, rightAns.height);
    }
    return output;
}
int height(BinaryTreeNode<int>* root){
    LargestBST ans= heightOfLargestBST(root);
    return ans.height;
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    int h= height(root);
    cout<<endl<<"Height of largest BST is : "<<h<<endl;
}
