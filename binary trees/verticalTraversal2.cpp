#include "binaryTree.h"
#include<bits/stdc++.h>
#include<map>
#include<vector>
//O(n)
void getVerticalOrder(BinaryTreeNode<int>* root, int hd, map<int, vector<int> > &m){
    if(root == NULL)
        return;
    m[hd].push_back(root->data);
    getVerticalOrder(root->left, hd-1, m);
    getVerticalOrder(root->right, hd+1, m);
}
void verticalTraversal(BinaryTreeNode<int>* root){
    if(root ==NULL)
        return;
    map<int, vector<int> > m;
    int hd=0;
    getVerticalOrder(root, hd, m);

    map<int, vector<int> > :: iterator it;
    for(it= m.begin(); it!=m.end(); it++){
        for(int i=0; i<it->second.size(); i++){
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 8 -1 9 -1 -1 -1 -1
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl;
    verticalTraversal(root);
}
