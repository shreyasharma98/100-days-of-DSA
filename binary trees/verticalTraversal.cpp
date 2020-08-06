//Given a binary tree, print it vertically.
/*
           1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9


The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9
minimum horizontal distance is -1 (for 4)
and maximum horizontal distance is 3(for 9)
*/
//Time complexity : O(w*n) w- width of BT, n- no. of nodes. worst case : O(n^2)
#include "binaryTree.h"
void minMax(BinaryTreeNode<int>* root, int *mini, int *maxi, int hd){   //hd is the horizontal distance of current node from root
    if(root== NULL)
        return;
    if(hd < *mini)
        *mini= hd;
    else if(hd > *maxi)
        *maxi= hd;
    minMax(root->left, mini, maxi, hd-1);
    minMax(root->right, mini, maxi, hd+1);
}
void printVertical_helper(BinaryTreeNode<int>* root, int line_no, int hd){
    if(root== NULL)
        return;
    if(hd== line_no){
        cout<<root->data<< " ";
    }
    printVertical_helper(root->left, line_no, hd-1);
    printVertical_helper(root->right, line_no, hd+1);
}
void printVertically(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    int mini=0, maxi=0;
    minMax(root, &mini, &maxi, 0);
    for(int i=mini; i<=maxi; i++){
        printVertical_helper(root, i, 0);
        cout<<endl;
    }
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl;
    printVertically(root);
}
