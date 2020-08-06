#include "binaryTree.h"
template <typename T>
class Node{
public:
    T data;
    Node<T>* next;

    Node(T data){
        this->data = data;
        next= NULL;
    }
};
class node2{
public:
    Node<int>* head;
    Node<int>* tail;
};
node2 constructLL_helper(BinaryTreeNode<int>* root){
    if(root== NULL){
        node2 ans;
        ans.head=NULL;
        ans.tail= NULL;
        return ans;
    }
    node2 left= constructLL_helper(root->left);
    node2 right= constructLL_helper(root->right);
    Node<int>* newNode= new Node<int>(root->data);
    if(left.tail != NULL){
        left.tail->next= newNode;
    }
    newNode->next= right.head;
    node2 output;
    if(left.head != NULL){
        output.head= left.head;
    }
    else{
        output.head= newNode;
    }
    if(right.tail != NULL){
        output.tail= right.tail;
    }
    else{
        output.tail= newNode;
    }
    return output;
}
Node<int>*  constructLL(BinaryTreeNode<int>* root){
    node2 ans= constructLL_helper(root);
    return ans.head;
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    Node<int>* head= constructLL(root);
    cout<<endl<< "Sorted LinkedList of the BST is : ";
    while(head != NULL){
        cout<<head->data<< " ";
        head= head->next;
    }
}
