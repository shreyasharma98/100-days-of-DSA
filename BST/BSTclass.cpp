#include<iostream>
#include<queue>
using namespace std;
template<typename T>

class BinaryTreeNode{
public:
	T data;
	BinaryTreeNode<T> *left;
	BinaryTreeNode<T> *right;

	BinaryTreeNode(T data){
		this->data= data;
		left= NULL;
		right=NULL;
	}
	~BinaryTreeNode(){
		delete left;
		delete right;
	}
};
class BST{
    BinaryTreeNode<int>* root;
    public:
        BST(){
            root= NULL;
        }
        ~BST(){
            delete root;
        }
        bool hasData(int data){
            return hasData(data, root);
        }

        void insert(int data){
            root= insert(data, root);
        }

        void deleteData(int data){
            root= deleteData(data, root);
        }

        void printTree(){
            printTree(root);
        }
      private:
          bool hasData(int data, BinaryTreeNode<int>* root){
              if(root==NULL)
                return false;
              if(root->data == data){
                return true;
              }
              else if(root->data > data){
                return hasData(data, root->left);
              }
              else{
                return hasData(data, root->right);
              }
          }
          BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* root){
            if(root == NULL){
                BinaryTreeNode<int>* newNode= new BinaryTreeNode<int>(data);
                return newNode;
            }
            if(root->data > data){
                root->left= insert(data, root->left);
            }else{
                root->right= insert(data, root->right);
            }
            return root;
          }
          BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* root){
            if(root == NULL)
                return NULL;
            if(root->data > data){
                root->left= deleteData(data, root->left);
                return root;
            }
            else if(root->data < data){
                root->right= deleteData(data, root->right);
                return root;
            }
            else{
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    return NULL;
                }
                else if(root->left == NULL){
                    BinaryTreeNode<int>* node= root->right;
                    root->right= NULL;
                    delete root;
                    return node;
                }
                else if(root->right == NULL){
                    BinaryTreeNode<int>* node= root->left;
                    root->left= NULL;
                    delete root;
                    return node;
                }
                else{
                    BinaryTreeNode<int>* rightMin= root->right;
                    if(rightMin != NULL)
                        rightMin= rightMin->left;
                    int node= rightMin->data;
                    root->data= node;
                    root->right= deleteData(node, root->right);
                    return root;
                }
            }
          }
          void printTree(BinaryTreeNode<int>* root){
            if(root == NULL)
                return;
            cout<<root->data<< " : ";
            if(root->left)
                cout<< "L:"<<root->left->data<< ", ";
            if(root->right)
                cout<< "R: "<<root->right->data;
            cout<<endl;
            printTree(root->left);
            printTree(root->right);
          }
};
int main(){
    BST *tree= new BST();
    int ch, input;
    cout<< "Enter your choice" <<endl<<" 1. insert"<<endl<<" 2. delete"<<endl <<" 3. search "<<endl;
    while(true){
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch){
        case 1:
            cout<< "Enter the number : ";
            cin>>input;
            tree->insert(input);
            break;
        case 2:
            cout<< "Enter the number : ";
            cin>>input;
            tree->deleteData(input);
            break;
        case 3:
            cout<< "Enter the number : ";
            cin>>input;
            if(tree->hasData(input)){
                cout<< "true"<<endl;
            }
            else{
                cout<< "false"<<endl;
            }
            break;
        default:
            tree->printTree();
            return 0;
            break;
        }
    }
}


