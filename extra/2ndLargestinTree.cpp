//Given a generic tree, find and return the node with second largest value in given tree.
//Return NULL if no node with required value is present.
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
class helper{
    public:
    TreeNode<int>* max;
    TreeNode<int>* smax;

    helper(TreeNode<int> *max, TreeNode<int>*smax){
        this->max= max;
        this->smax= smax;
    }
};
helper help(TreeNode<int>* root){
    if(root == NULL){
        helper r(NULL,NULL);
        return r;
    }
    helper ans(root,NULL);  //max is root and smax is null
    for(int i=0; i<root->children.size(); i++){
        helper temp= help(root->children[i]);
        if(temp.max->data > ans.max->data){
            if(temp.smax == NULL){
                ans.smax= ans.max;
                ans.max= temp.max;
            }
            else{
                if(temp.smax->data > ans.max->data){
                    ans.smax= temp.smax;
                    ans.max= temp.max;
                }
                else{
                    ans.smax= ans.max;
                    ans.max= temp.max;
                }
            }
        }
        else{
            if(ans.max->data != temp.max->data && (ans.smax == NULL || temp.max->data > ans.smax->data)){
                ans.smax= temp.max;
            }
        }
    }
    return ans;
}
TreeNode <int>* secondLargest(TreeNode<int> *root) {
    if(root == NULL)
        return root;
    helper ans= help(root);
    return ans.smax;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}

