//Given a binary tree, convert it to its sum tree.
//That is, replace every node data with sum of its immediate children, keeping leaf nodes 0.
//And then return its preorder.
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
void preOrder(BinaryTreeNode<int>* root){
    if(root== NULL)
        return;
    if(root->left != NULL && root->right != NULL){
        int sum= root->left->data + root->right->data;
        v.push_back(sum);
    }
    if(root->left!= NULL && root->right == NULL)
        v.push_back(root->left->data);
    if(root->left== NULL && root->right != NULL)
        v.push_back(root->right->data);
    if(root->left == NULL && root->right == NULL){
        v.push_back(0);
    }
    preOrder(root->left);
    preOrder(root->right);

}
vector<int> sumTree(BinaryTreeNode<int>* root){
    	/* Don't write main().
	* Don't read input from, it is passed as function argument.
	* Return output and don't print it.
	* Taking input and printing output is handled automatically.
	*/
    preOrder(root);
    return v;
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
    vector<int> ans= sumTree(root);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}
