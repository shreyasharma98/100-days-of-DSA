 //Given a binary tree having N nodes, print its boundary traversal.

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
 void printleft(BinaryTreeNode<int>* root){
     if(root == NULL)
         return;
    if(root->left){
        cout<<root->data<<" ";
        printleft(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        printleft(root->right);
    }
}
void printleaves(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    printleaves(root->left);
    if(root->left == NULL && root->right == NULL)
        cout<<root->data<<" ";
    printleaves(root->right);
}
void printright(BinaryTreeNode<int>* root){
    if(root== NULL)
        return;
    if(root->right){
        printright(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left){
        printright(root->left);
        cout<<root->data<<" ";
    }
}
void solve(BinaryTreeNode<int>* root){
    	/* Don't write main().
	* Don't read input, it is passed as function argument.
	*/
	if(root== NULL)
        return;
    cout<<root->data<<" ";
    printleft(root->left);
    printleaves(root->left);
    printleaves(root->right);
    printright(root->right);
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
    solve(root);
}
