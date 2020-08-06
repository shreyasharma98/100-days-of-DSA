//Given a generic tree and an integer n. Find and return the node with next larger element in the Tree
//i.e. find a node with value just greater than n.
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) {
        this->data = data;
    }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }

};
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    if(root == NULL)
        return root;
	TreeNode<int>* ans= NULL;
    if(root->data > n)
        ans= root;
    TreeNode<int>* temp;
    for(int i=0; i<root->children.size(); i++){
        temp= nextLargerElement(root->children[i], n);
        if(ans == NULL)
        	ans= temp;
        if(temp!= NULL)
            if(temp->data < ans->data)
            	ans= temp;
    }
	return ans;
}

int main() {
    int n;
    cin >> n;
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = nextLargerElement(root, n);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
    else {
        cout << INT_MIN << endl;
    }
}
