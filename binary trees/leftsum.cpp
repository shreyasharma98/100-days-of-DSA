 // Given a binary tree having N number of nodes. 
 // Find and return the sum of all left nodes present in the input binary tree. 
 // That is, you need to take sum of all nodes which are left child of some node.

 #include<iostream>
 #include<queue>
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
 int leftSum(BinaryTreeNode<int>* root, int isLeft){
    if(root == NULL)
        return 0;
    int l= leftSum(root->left, 1);
    int r= leftSum(root->right, 0);
    if(isLeft)
        return l+ r+ root->data;

    return l+ r;
 }
 int leftSum(BinaryTreeNode<int>* root){
    return leftSum(root, 0);
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
    cout << leftSum(root) << endl;
}
 