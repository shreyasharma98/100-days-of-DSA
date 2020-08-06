//Given a binary tree having N nodes. Check if all the leaves are at same level. Print "YES" or "NO"

#include<bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
bool checkLeaves_helper(BinaryTreeNode<int>* root, int lvl, int leaflvl){
    if(root == NULL){
        return true;
    }
    if(root->left == NULL && root->right == NULL){
        if(leaflvl == 0){
            leaflvl= lvl;
            return true;
        }
        else{
            return (leaflvl == lvl);
        }
    }
    return checkLeaves_helper(root->left, lvl+1, leaflvl) && checkLeaves_helper(root->right, lvl+1, leaflvl);

}
void checkLeaves(BinaryTreeNode<int>* root){
    /* Don't write main().
     * Don't read input, is is passed as function argument.
     */
    int leaflvl =0;
    bool ans= checkLeaves_helper(root, 0, leaflvl);
    if(ans)
        cout<<"YES";
    else
        cout<<"NO";
}



int main() {
    BinaryTreeNode<int>* root = takeInput();
    checkLeaves(root);
