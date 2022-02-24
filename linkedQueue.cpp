#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class LinkedQueue{
    public: 
        Node* front;
        Node* rear;
    LinkedQueue(){
        front = rear = NULL;
    }
    void enqueue(int number){
        Node* temp = new Node(number);

        if (front == NULL)
        {
            front = temp;
            rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }


    void display(){
        if (front == NULL)
        {
            cout << " Empty " << endl;
            return;
        }

        Node* current = front;
        while (current)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    void dequeue(){
        if (front == NULL)
        {
            cout << "No elements in queue" << endl;
            return;
        }
        
        Node* temp = front;
        front = front->next;
        delete temp;        
    }
};

int main(){
    LinkedQueue queue;
    queue.enqueue(50);
    queue.enqueue(44);
    queue.display();
    queue.dequeue();
    queue.display();
    queue.dequeue();
    queue.display();
    queue.enqueue(44);
    queue.display();
}