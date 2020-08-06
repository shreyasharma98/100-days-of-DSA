//Given a Binary Tree with N number of nodes, for each node create a new duplicate node,
//and insert that duplicate as left child of the original node.
#include "binaryTree.h"

void insertDuplicateNode(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    BinaryTreeNode<int>* dupNode= new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int>* temp= root->left;
    root->left= dupNode;
    dupNode->left= temp;

    insertDuplicateNode(temp);
    insertDuplicateNode(root->right);
}
void printLevelOrderTraversal(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    BinaryTreeNode<int>* curr;
    while(q.size()!=0){
        curr= q.front();
        q.pop();
        if(curr != NULL){
            cout<<curr->data<<" ";
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        else{
            if(q.size() != 0){
                cout<<endl;
                q.push(NULL);
            }
        }
    }
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl<< "After inserting duplicate Nodes : "<<endl;
    insertDuplicateNode(root);
    printLevelOrderTraversal(root);
}
