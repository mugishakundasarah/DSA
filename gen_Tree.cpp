#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Node{
    int value;
    Node* parent;
    vector<Node*> children;
};

Node* addNode(Node *parent, int value){
    Node* newNode = new Node();
    newNode->value = value;
    newNode->parent = parent;
    if(parent!=NULL){
        parent->children.push_back(newNode);
    }
    return newNode;
}


void display(Node* rootNode){
    list<Node*> queue;
    queue.push_back(rootNode);

    while (!queue.empty())
    {
        int size = queue.size();
        while (size > 0)
        {
            Node* current = queue.front();
            cout << current->value;
            for(Node* i:current->children){
                queue.push_back(i);
            }
            queue.pop_front();
            size --;
        }
        cout << endl;
    }
    
}

int main(){
    Node* root = addNode(NULL, 4);
    Node* firstChild = addNode(root, 3);
    Node* secondChild = addNode(root, 5);
    Node* thirdChild = addNode(root, 6);
    Node* fourthChild = addNode(root, 10);
    Node* firstSibling = addNode(firstChild, 7);
    Node* secondSibling = addNode(firstChild, 8);
    Node* thirdSibling = addNode(secondChild, 9);

    display(root);
}