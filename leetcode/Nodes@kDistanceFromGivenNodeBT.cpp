/*
We are given a binary tree (with root node root), a target node, and an integer value K.
Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.
Example :
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
Output: [7,4,1]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, bool> seen;

    public:
    void preorder(TreeNode* root){
        if(!root)
            return;
        seen[root]= false;
        if(root->left){
            parent[root->left]= root;
            preorder(root->left);
        }
        if(root->right){
            parent[root->right]= root;
            preorder(root->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(!root || !target)
            return {};
        preorder(root);  //using preorder(Ro,L,R) to add every node's parent to map
        queue<TreeNode* > q;
        q.push(target);
        q.push(NULL);
        seen[target]= true;
        while(!q.empty() && K> 0){
            TreeNode* top= q.front();
            q.pop();
            if(top){
                if(top->left && !seen[top->left]){
                    q.push(top->left);
                    seen[top->left]= true;
                }
                if(top->right && !seen[top->right]){
                    q.push(top->right);
                    seen[top->right]= true;
                }
                if(parent[top] && !seen[parent[top]]){
                    q.push(parent[top]);
                    seen[parent[top]]= true;
                }
            }
            else{
                q.push(NULL);
                K--;
            }
        }
        vector<int> ans;
        while(!q.empty()){
            if(q.front()){
                ans.push_back(q.front()->val);
                q.pop();
            }
            else
                q.pop();
        }
        return ans;
    }
};
