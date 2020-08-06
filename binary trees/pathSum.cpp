//Given a binary tree and a number k, print out all root to leaf paths
//where the sum of all nodes value is same as the given number k.
#include "binaryTree.h"
#include<vector>

void pathSum_helper(BinaryTreeNode<int>* root, vector<int> &path, int sum){
    if(root== NULL){
        return;
    }
    sum -= root->data;
    path.push_back(root->data);
    if(root->left == NULL && root->right== NULL){
        if(sum==0){
            for(int i=0; i<path.size(); i++){
                cout<<path[i]<< " ";
            }
            cout<<endl;
        }
        path.pop_back();
        return;
    }
    pathSum_helper(root->left, path, sum);
    pathSum_helper(root->right, path, sum);
    path.pop_back();
}

void pathSum(BinaryTreeNode<int>* root, int sum){
    vector<int> path;
    pathSum_helper(root, path, sum);
}

int main(){
    BinaryTreeNode<int>* root= takeInput();
    int sum;
    cout<< endl<<"Enter the sum : ";
    cin>>sum;
    pathSum(root, sum);
}
