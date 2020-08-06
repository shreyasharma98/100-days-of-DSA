//Given a binary tree, return the longest path from leaf to root.
//Longest means, a path which contain maximum number of nodes from leaf to root.
#include "binaryTree.h"
#include<vector>
vector<int>* longestPath(BinaryTreeNode<int>* root){
    if(root== NULL)
        return NULL;
    if(root->left== NULL && root->right==NULL){
        vector<int>* v= new vector<int>();
        v->push_back(root->data);
        return v;
    }
    vector<int>* leftAns= longestPath(root->left);
    vector<int>* rightAns= longestPath(root->right);
    if(root->right == NULL){
        leftAns->push_back(root->data);
        return leftAns;
    }
    else if(root->left == NULL){
        rightAns->push_back(root->data);
        return rightAns;
    }
    else{
        if(rightAns->size() > leftAns->size()){
            rightAns->push_back(root->data);
            delete leftAns;
            return rightAns;
        }
        else{
            leftAns->push_back(root->data);
            delete rightAns;
            return leftAns;
        }
    }
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    vector<int>* ans= longestPath(root);
    cout<<endl<< "longest leaf to root path is : ";
    for(int i=0; i<ans->size(); i++){
        cout<<ans->at(i)<<endl;
    }
    return 0;
}
