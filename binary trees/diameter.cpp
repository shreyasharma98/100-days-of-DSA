//Diameter of a Binary Tree
#include<bits/stdc++.h>
#include "binaryTree.h"
int height(BinaryTreeNode<int>* root){
    if(root== NULL)
        return 0;
    return max(height(root->left), height(root->right)) +1;
}
int diameter(BinaryTreeNode<int>* root){
    if(root== NULL)
        return 0;
    int a= height(root->left)+ height(root->right);
    int b= diameter(root->left);
    int c= diameter(root->right);
    return max(a, max(b,c));
}
//Above height func has a time complexity of O(n) and diameter func has a time complexity of O(n*h) where h is the height
//BETTER APPROACH
pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
    if(root== NULL){
        pair<int, int> p;
        p.first= 0;
        p.second= 0;
        return p;
    }
    pair<int, int> leftAns= heightDiameter(root->left);
    pair<int, int> rightAns= heightDiameter(root->right);
    int lh= leftAns.first;
    int ld= leftAns.second;
    int rh= rightAns.first;
    int rd= rightAns.second;
    int height= 1+ max(lh, rh);
    int diameter= max(lh+rh, max(ld, rd));
    pair<int, int> p;
    p.first= height;
    p.second= diameter;
    return p;
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    pair<int,int> p= heightDiameter(root);
    cout<< "Height: "<<p.first<<endl;
    cout<< "Diameter : "<<p.second<<endl;

}
