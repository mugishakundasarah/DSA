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
    public: 
        Doubly(){
            head = NULL;
        }

        Node *addBefore(int data){
            Node *newNode = new Node(data);
            if(head == NULL){
                head = newNode;
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
}; 

int main(){
    Doubly doubly1;
    doubly1.addBefore(30);
    doubly1.addBefore(31);
    doubly1.addBefore(56);
    doubly1.printFromFront();
}