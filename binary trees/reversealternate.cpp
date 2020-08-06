//Given a perfect binary tree having N nodes, reverse its alternate levels.
//That is reverse level 2, level 4 and so on. Root is at level 1.
//Print the inorder traversal of output tree.

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
 void print(BinaryTreeNode<int>* root){
    if (root == NULL)
       return;
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
void reverse(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2, int k){
    if(root1 == NULL || root2 == NULL){
        return;
    }
    if(k%2 == 0)
        swap(root1->data, root2->data);
    reverse(root1->left, root2->right, k+1);
    reverse(root1->right, root2->left, k+1);
}
void solve(BinaryTreeNode<int>* root){
    	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Print the preorder traversal of output tree
	*/
	reverse(root->left, root->right, 2);
    print(root);
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
