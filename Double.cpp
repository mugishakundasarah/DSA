#include <iostream>
using namespace std;

struct Node {
    public: 
        Node* previous;
        int data;
        Node*next;
    public: 
        Node(int data){
            this->previous = NULL;
            this->data = data;
            this->next = NULL;
        }
};

struct Doubly{
    public: 
        Node *head;
        Node *tail;
    public: 
        Doubly(){
            head = NULL;
            tail = NULL;
        }

        Node *addBefore(int data){
            Node *newNode = new Node(data);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                return newNode;
            }

            head -> previous = newNode;
            newNode-> next = head;
            head =  newNode;
            return newNode;
        }

        void printFromFront(){
            if(head == NULL){
                cout << "Is empty " << endl;
            }
            Node* current = head;
            while (current != NULL)
            {
                cout << current->data << endl;
                current = current->next;             
            }         
        }

        Node* addToEnd(int data) {
            Node* newNode = new Node(data);
            if(head==NULL){
                head = newNode;
                tail = newNode;
                return newNode;
            }
        
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->previous = current;
            
            tail = newNode;
            return newNode;
        } 

        void printFromEnd(){
            if (head == NULL)
            {
                cout << "Empty list " << endl;
                return;
            }
            
            Node* current = tail;
            while (current != NULL)
            {
                cout << current->data << endl;
                current = current->previous;
            }
        }

        void insertAfter(Node *node, int data){
            Node* newNode = new Node(data);
            if (node->next == NULL)
            {
                node->next = newNode;
                newNode->previous = node;
                tail = newNode;
            }

            Node *after = node->next;
            node->next = newNode;
            newNode->previous = node;
            newNode->next = after;
            after->previous = newNode;
        }
}; 

int main(){
    Doubly doubly1; 
    Node* insert1 = doubly1.addBefore(30);
    Node* insert2 = doubly1.addBefore(31);
    Node* insert3 = doubly1.addBefore(56);

    Node* insert4 = doubly1.addToEnd(79);
    Node* insert5 = doubly1.addToEnd(81);
    doubly1.printFromEnd();


    doubly1.insertAfter(insert2, 1003);


    cout << "after insert " << endl;
    doubly1.printFromFront();
}