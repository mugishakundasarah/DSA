#include <iostream>
using namespace std;


//there are 3 types of dft binary tree traversal
//in order(left,root,right), pre-order(root,left,right),
//post-order(left,right,root)

class Node{
    public: 
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

class BinaryTree{
    public: 
        Node* root;
        BinaryTree(){
            this->root = NULL;
        }
    Node* addNode(Node *current, int data, bool isRight){
        Node *newNode= new Node(data);
        if(current == NULL){
            root = newNode;
        }else{
            if(isRight){
                current->right = newNode;
            }else{
                current->left = newNode;
            }       
        }
        return newNode;
    }

    void inOrderTraversal(Node* root){
        if (root == NULL)
        {
            return;
        }
        inOrderTraversal(root->left);
        cout << root->data << " " ;
        inOrderTraversal(root->right);
    }

    void preOrder(Node* root){
        if(root==NULL){
            return;
        }
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrderTraversal(Node* root){
        if(root == NULL){
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
};

int main(){
    BinaryTree bt;
    Node* root = bt.addNode(NULL, 1, false);
    Node* left = bt.addNode(root, 2, false);
    Node* right = bt.addNode(root, 7, true);
    Node* lLeft = bt.addNode(left, 5, false);
    Node* rLeft = bt.addNode(left, 4, true);
    Node* rlLeft = bt.addNode(lLeft, 3, true);
    Node* lrLeft = bt.addNode(rLeft, 6, false);

    Node* lRight = bt.addNode(right, 9, false);
    Node* rRight = bt.addNode(right, 10, true);
    Node* rlRight = bt.addNode(lRight, 11, true);
    Node* lrRight = bt.addNode(rRight, 3,false);
    Node* rrRight = bt.addNode(rRight, 15, true);

    cout << "Inorder" << endl;
    bt.inOrderTraversal(root);
    cout << endl;

    cout << "Preorder" << endl;
    bt.preOrder(root);
    cout << endl;

    cout << "Postorder" << endl;
    bt.postOrderTraversal(root);
    cout << endl;
}   