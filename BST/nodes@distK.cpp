//Given a binary tree, a node and an integer K,
//print nodes which are at K distance from the the given node.
#include "binaryTree.h"
void print_helper(BinaryTreeNode<int>* root, int k){
    if(root== NULL)
        return;
    if(k== 0){
        cout<<root->data<< endl;
        return;
    }
    print_helper(root->left, k-1);
    print_helper(root->right, k-1);
}
int printNodes(BinaryTreeNode<int>* root, int node, int k){
    if(root== NULL)
        return -1;
    if(root->data == node){
        print_helper(root, k);
        return 0;
    }
    int lD= printNodes(root->left, node, k);
    if(lD != -1){
        if(lD+1== k){
            cout<<root->data<<endl;
        }
        print_helper(root->right, k-lD-2);
    }
    int rD= printNodes(root->right, node, k);
    if(rD != -1){
        if(rD+1== k){
            cout<<root->data<<endl;
        }
        print_helper(root->left, k-rD-2);
    }
    if (lD == -1 && rD == -1)
        return -1;
    if (lD != -1)
        return lD + 1;
    else
        return rD + 1;
}
void nodesAtdistanceKfromRoot(BinaryTreeNode<int>* root, int node, int k){
    printNodes(root, node, k);
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl<< "Enter the node : ";
    int node;
    cin>>node;
    cout<<"Enter the distance : ";
    int k;
    cin>>k;
    nodesAtdistanceKfromRoot(root, node, k);
}
