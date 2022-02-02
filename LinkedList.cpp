#include <iostream>
using namespace std;

class Node{
    public:
        Node *head;
    public:
        int data;
        Node *next;

    public:
        Node(){
            this->next=NULL;
            head = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList{
    public:
        Node *head;
    public:
        LinkedList() {
            head= NULL;
        }
    void addNewNode(int data){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void displayNode() {
        if (head == NULL)
        {
            cout << "Empty list: " << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data ;
            temp = temp->next;
        }
    }
    void deleteNode(int position){
        if(head == NULL){
            cout << "Empty list " << endl;
            return;
        }

        if(position ==1 ){
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        int size = 0;
        Node *current = head;
        while (current != NULL)
        {
            size++;
            current = current->next;
        }

        if (size < position)
        {
            cout << "Invalid operation";
            return;
        }

        current = head;
            Node *previous;
        while (position > 1)
        {
            position--;
            previous = current;
            current = current->next;
        }
        previous->next=current->next;
        delete current;
    }
    void insertNode(int position, int data){
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            if (position > 1)
            {
                return;
            }
            head = newNode;
            return;
        }

        Node *current = head;
        int size = 0;
        while (current!=NULL)
        {
            size++;
            current = current -> next;
        }

        if(size < position) {
            cout << "Invalid operation" << endl;
            return;
        }

        if(position == 1){
            Node *temp = head;
            newNode->next = temp;
            head = newNode;
            return;
        }

        Node *previous;
        current = head;
        cout << "THE DATA POSITION IS " << position << " the value is " << current->data << endl; 
        while (position > 1)
        {
            position--;
            previous = current;
            current = current->next;
            cout << "THE DATA POSITION IS " << position << " the value is " << current->data << endl; 
        }
        previous->next = newNode;
        newNode->next = current;
    }
    Node* searchByPosition(int position){
        if(head == NULL){
            return NULL;
        }
        int count = 0;
        Node *current; 
        current = head;
        while (current != NULL)
        {
            count++;
            if (count == position)
            {
                return current;
            }
            current = current -> next;
        }
        return NULL;
    }    
    Node* searchByValue(int value){
        if(head == NULL){
            return NULL;
        }
        int count = 0;
        Node *current; 
        current = head;
        while (current != NULL)
        {
            count++;
            if (current->data == value)
            {
                return current;
            }
            current = current -> next;
        }
        return NULL;
    }        
};

int main(){
    LinkedList list;
    list.addNewNode(1);
    list.addNewNode(2);
    list.addNewNode(3);
    list.addNewNode(4);
    list.displayNode();
    cout << endl;
    // list.deleteNode(7);
    list.insertNode(3, 9);
    cout << endl;
    list.displayNode();

    cout << endl;
    Node* result1 = list.searchByPosition(0);
    if (result1 != NULL)
    {
        cout << "The index of value is " << result1->data << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    
    Node* result2 = list.searchByValue(9);
    if (result2 != NULL)
    {
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }   
    return 0;
}