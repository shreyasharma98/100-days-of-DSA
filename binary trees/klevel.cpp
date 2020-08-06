 // Given a binary tree with N number of nodes, find and return the sum of all nodes which are at Kth level.
 // Root is at level 1.

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
 long long sumOfNodes(BinaryTreeNode<int>* root, int k){
 	if(root == NULL)
 		return 0;
 	if(k== 1)
 		return root->data;
 	long long sum= 0;
 	if(root->left)
 		sum+= sumOfNodes(root->left, k-1);
 	if(root->right, k-1)
 		sum+= sumOfNodes(root->right, k-1);
 	return sum;
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
    int k;
    cin>>k;
    cout << sumOfNodes(root, k) << endl;
}
 