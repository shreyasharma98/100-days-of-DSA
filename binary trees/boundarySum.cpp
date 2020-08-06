//Given a Binary Tree, find and return the sum of all boundary nodes.
#include "binaryTree.h"

long long leftBoundary(BinaryTreeNode<int>* root){
    long long sum=0;
	if(root != NULL){
        if(root->left){
            sum += root->data;
            leftBoundary(root->left);
        }
        else if(root->right){
            sum += root->data;
            leftBoundary(root->right);
        }
    }
    return sum;
}
long long rightBoundary(BinaryTreeNode<int>* root){
    long long sum=0;
	if(root != NULL){
        if(root->right){
            leftBoundary(root->right);
            sum += root->data;
        }
        else if(root->left){
            leftBoundary(root->left);
            sum += root->data;
        }
    }
    return sum;
}
long long leaves(BinaryTreeNode<int>* root){
    long long sum=0;
    if(root != NULL){
        sum += leaves(root->left);
        if(root->left == NULL && root->right == NULL){
            sum += root->data;
        }
        sum += leaves(root->right);
    }
    return sum;
}
long long sumBoundaryNodes(BinaryTreeNode<int>*root) {
	/*Write your code here.
	*Don't write main().
	*Don't take input, it is passed as function argument.
	*Don't print output.
	*Taking input and printing output is handled automatically.
	*/
    if(root!= NULL){
        long long sum= root->data;
    	sum += leftBoundary(root->left);
        sum += leaves(root->left);
        sum += leaves(root->right);
        sum += rightBoundary(root->right);
        return sum;
    }
    return 0;
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl<< "sum of boundary elements are : ";
    long long ans= sumBoundaryNodes(root);
    cout<<ans;
}
