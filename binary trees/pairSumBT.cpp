//Given a binary tree and an integer S, print all the pair of nodes whose sum equals S
#include "binaryTree.h"
#include<vector>
#include<algorithm>
void BSTvector(BinaryTreeNode<int>* root, vector<int> &v){
    if(root == NULL)
        return;
    v.push_back(root->data);
    BSTvector(root->left, v);
    BSTvector(root->right, v);
}
void pairSum(BinaryTreeNode<int>* root, int sum){
    vector<int> v;
    BSTvector(root, v);
    sort(v.begin(), v.end());
    int si=0;
    int ei= v.size() -1;
    while(si < ei){
        if(v[si] + v[ei] == sum){
            cout<<v[si]<< " "<<v[ei]<<endl;
            si++;
            ei--;
        }
        else if(v[si] + v[ei] > sum)
            ei--;
        else
            si++;
    }
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl<< "Enter the sum : ";
    int sum;
    cin>>sum;
    pairSum(root, sum);
}
