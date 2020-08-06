//Given a binary tree. Print the Top View of Binary Tree.
//Print the nodes from left to right order.
#include<bits/stdc++.h>
#include "binaryTree.h"
void fillMap(BinaryTreeNode<int>* root, int hd, int lvl, map<int, pair<int, int> > &m){
    if(root == NULL)
        return;
    if(m.count(hd)== 0)
        m[hd]= make_pair(root->data, lvl);
    else if((m[hd].second > lvl))
        m[hd]= make_pair(root->data, lvl);
    fillMap(root->left, hd-1, lvl+1, m);
    fillMap(root->right, hd+1, lvl+1, m);
}
void topView(BinaryTreeNode<int>* root){
    map<int, pair<int, int> > m;
    fillMap(root, 0 , 0, m);
    map<int, pair<int,int> >::iterator it;
    for(it= m.begin(); it != m.end(); it++){
        cout<<it->second.first<< " ";
    }
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl<< "TOP VIEW : "<<endl;
    topView(root);
}

