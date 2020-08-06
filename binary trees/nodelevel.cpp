//Given a binary tree having N nodes and an integer M you have to return the level of node M.
//Consider root to be at level 1.
#include<iostream>
#include<queue>
 #include<vector>
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
int level(BinaryTreeNode<int>*root, int M, int k){
    if(root == NULL)
        return 0;
    if(root->data== M){
        return k;
    }
    int lans=0, rans=0;
    lans= level(root->left, M, k+1);
    if(lans != 0)
        return lans;
    rans= level(root->right, M, k+1);
    if(rans != 0)
        return rans;

}
int solve(BinaryTreeNode<int>* root, int M){
    // Write your code here
	return level(root, M, 1);
}

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

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n;
    cin>>n;
    int ans= solve(root, n);
    cout<<ans<<endl;
}
