//Given a binary tree, print the zig zag order
//i.e print level 1 from left to right, level 2 from right to left and so on.
//This means odd levels should get printed from left to right and even level right to left.
#include<stack>
#include "binaryTree.h"
void zigZagTree(BinaryTreeNode<int>* root){
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    BinaryTreeNode<int>* curr;
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            curr= s1.top();
            s1.pop();
            cout<<curr->data<<" ";
            if(curr->left)
                s2.push(curr->left);
            if(curr->right)
                s2.push(curr->right);
        }
        cout<<endl;
        while(!s2.empty()){
            curr= s2.top();
            s2.pop();
            cout<<curr->data<<" ";
            if(curr->right)
                s1.push(curr->right);
            if(curr->left)
                s1.push(curr->left);
        }
        cout<<endl;
    }
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl;
    zigZagTree(root);
}
