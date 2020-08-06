#include "binaryTree.h"
#include<cstdlib>
class Pair{
public:
    bool isBal;
    int height;
};
Pair isBalanced_helper(BinaryTreeNode<int>* root){
    if(root == NULL){
        Pair p;
        p.isBal= true;
        p.height= 0;
        return p;
    }
    Pair leftAns= isBalanced_helper(root->left);
    Pair rightAns= isBalanced_helper(root->right);
    bool flag;
    if((!leftAns.isBal) || (!rightAns.isBal) || abs(leftAns.height- rightAns.height) > 1)
        flag= false;
    else
        flag= true;
    Pair pAns;
    pAns.height= max(leftAns.height, rightAns.height) + 1;
    pAns.isBal= flag;
    return pAns;
}
bool isBalanced(BinaryTreeNode<int>* root){
    Pair ans= isBalanced_helper(root);
    return ans.isBal;
}
int main(){
    BinaryTreeNode<int>* root= takeInput();
    cout<<endl;
    bool ans= isBalanced(root);
    if(ans == true){
        cout<<"BT is balanced"<<endl;
    }
    else
        cout<<"BT is not balanced"<<endl;
}
