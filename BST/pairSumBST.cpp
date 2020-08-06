//Given a binary search tree and an integer S,
//find pair of nodes in the BST which sum to S. You can use extra space only O(log n).
#include "binaryTree.h"
#include<stack>
int countNodes(BinaryTreeNode<int>* root){
    if(root== NULL)
        return 0;
    return countNodes(root->left)+ countNodes(root->right) + 1;
}
void pairSumBST(BinaryTreeNode<int>* root, int sum){
    if(root== NULL)
        return;
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    int totalNodes= countNodes(root);
    int count= 0;
    BinaryTreeNode<int>* curr= root;
    s1.push(root);
    while(curr->left!= NULL){
        s1.push(curr->left);
        curr= curr->left;
    }
    curr= root;
    s2.push(root);
    while(curr->right != NULL){
        s2.push(curr->right);
        curr= curr->right;
    }
    while(count < totalNodes - 1){
        BinaryTreeNode<int>* top1= s1.top();
        BinaryTreeNode<int>* top2= s2.top();
        if(top1->data + top2->data == sum){
            cout<<top1->data<<" "<<top2->data<<endl;
            s1.pop();
            s2.pop();
            count += 2;
            if(top1->right!= NULL){
                s1.push(top1->right);
                top1= top1->right;
                while(top1->left!= NULL){
                    s1.push(top1->left);
                    top1= top1->left;
                }
            }
            if(top2->left!= NULL){
                s2.push(top2->left);
                top2= top2->left;
                while(top2->right!= NULL){
                    s2.push(top2->right);
                    top2= top2->right;
                }
            }
        }
        else if(top1->data + top2->data > sum){
            s2.pop();
            count++;
            if(top2->left!= NULL){
                s2.push(top2->left);
                top2= top2->left;
                while(top2->right!= NULL){
                    s2.push(top2->right);
                    top2= top2->right;
                }
            }
        }
        else{
            s1.pop();
            count++;
            if(top1->right!= NULL){
                s1.push(top1->right);
                top1= top1->right;
                while(top1->left!= NULL){
                    s1.push(top1->left);
                    top1= top1->left;
                }
            }
        }

    }
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl<< "Enter the sum : ";
    int sum;
    cin>>sum;
    pairSumBST(root, sum);
}
