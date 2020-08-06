//Given a BST and an integer k. Find and return the path from the node with data k and root.
//Return null otherwise.
//Assume that BST contains all unique elements.
#include "binaryTree.h"
#include<vector>
vector<int>* root2nodePath(BinaryTreeNode<int>* root, int k){
    if(root== NULL)
        return NULL;
    if(root->data == k){
        vector<int>* output= new vector<int>();
        output->push_back(root->data);
        return output;
    }
    if(root->data > k){
        vector<int>* leftAns= root2nodePath(root->left, k);
        if(leftAns != NULL){
            leftAns->push_back(root->data);
            return leftAns;
        }
        return NULL;
    }
    else{
        vector<int>* rightAns= root2nodePath(root->right, k);
        if(rightAns != NULL){
            rightAns->push_back(root->data);
            return rightAns;
        }
        return NULL;
    }
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl<< "Enter the element : ";
    int k;
    cin>>k;
    vector<int>* ans= root2nodePath(root, k);
    cout<< "Root to node path is : ";
    for(int i=0; i<ans->size(); i++){
        cout<< ans->at(i) <<" ";
    }
}
