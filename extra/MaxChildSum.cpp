//Given a tree, find and return the node for which sum of data of all children and the node itself is maximum.
//In the sum, data of node itself and data of immediate children is to be taken.
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

TreeNode<int>* helper(TreeNode<int> *root, int sum){

    TreeNode<int>* max= root;								//considering root node to be max
    int maxsum=root->data;
    for(int i=0; i<root->children.size(); i++){				//for root node
        maxsum+= root->children[i]->data;
    }
    TreeNode<int>* ans;

    for(int i=0; i<root->children.size(); i++){				//for children nodes
        ans= helper(root->children[i],sum);
        int child_sum= ans->data;
        for(int j=0 ; j<ans->children.size() ; j++){		//for children of child node in ans
            child_sum+=ans->children[j]->data;
        }

    	if(child_sum > maxsum){
        	max= ans;
        	maxsum= child_sum;
    	}
    }
    return max;
}
TreeNode<int>* maxSumNode(TreeNode<int> *root){
	int sum=0;
    TreeNode<int>* x;
    x= helper(root, sum);
    return x;
}

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

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxSumNode(root);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }
}
