//Given a binary tree, find and return the min and max data value of given binary tree.
#include<climits>
#include<algorithm>
#include <iostream>
#include <queue>
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

class PairAns {
    public :
    int min;
    int max;
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter root data : ";
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
        cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

PairAns minmax(BinaryTreeNode<int>* root){
    if(root == NULL){
        PairAns p;
        p.max= 0;
        p.min= INT_MAX;
        return p;
    }
    PairAns leftAns= minmax(root->left);
    PairAns rightAns= minmax(root->right);
    int maxl= leftAns.max;
    int minl= leftAns.min;
    int maxr= rightAns.max;
    int minr= rightAns.min;
    int maxAns= max(root->data, max(maxl, maxr));
    int minAns= min(root->data, min(minl, minr));
    PairAns p;
    p.max= maxAns;
    p.min= minAns;
    return p;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    PairAns ans = minmax(root);
    cout<<endl;
    cout << "maximum : "<< ans.max << " minimum : " << ans.min << endl;
}
