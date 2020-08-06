//Given a binary tree having N nodes and an integer M, return the postorder successor of M.
//Return -1 if there is no postorder successor of M.
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
vector<int> v;
void postorder(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    v.push_back(root->data);
}
int solve(BinaryTreeNode<int>* root, int M){
    postorder(root);
    for(int i=0; i<v.size()-1; i++){
        if(v[i]== M)
            return v[i+1];
    }
    return -1;
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
