//Given two Generic trees, return true if they are structurally identical
//i.e. they are made of nodes with the same values arranged in the same way.
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

bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {

    if(root1 == NULL && root2== NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL)
        return false;
    if(root1->children.size() != root2->children.size())
         return false;
    if(root1->data != root2->data)
         return false;
    int i=0;
    while(i<root1 ->children.size()){
        TreeNode<int>* child1= root1->children[i];
        TreeNode<int>* child2= root2->children[i];
        if(isIdentical(child1, child2))
            i++;
        else
            return false;
    }
    return true;
}
int main() {
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    if(isIdentical(root1, root2)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
