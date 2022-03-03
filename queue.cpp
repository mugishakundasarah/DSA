#include <iostream>
using namespace std;

// implementation of the queue data structure
struct Queue{
    int front, rear, capacity; 
    int *queue; 

    Queue(int size){
        front = 0;
        rear = 0;      
        capacity = size;
        queue = new int;
    };

    void checkFull(){
        if(rear == capacity){
            cout << "The queue is Full. " << endl;
            return;
        }
    }

    void checkEmpty(){
        if(rear == front){
            cout << "Queue is empty" << endl;
            return;
        }
    }
    void enqueue(int data){
        checkFull();
        queue[rear] = data;
        rear++;
    }

    void display(){
        checkEmpty();
        for (int i = front; i < rear; i++)
        {
            cout << queue[i] << ",";
        }
        cout << endl;
    }

    void dequeue(){
        checkEmpty();
        for (int i = 0; i < rear-1; i++)
        {
            queue[i] = queue[i+1];
        }
        rear--;      
    }
    int readFront(){
        checkEmpty();
        return queue[front];
    }
};

int main(){
    Queue t(10);
    t.enqueue(50);
    t.enqueue(30);
    t.enqueue(70);
    t.enqueue(90);
    t.display();
    t.dequeue();
    cout << " Front val is " << t.readFront() << endl;
    t.display();

    t.dequeue();
    cout << " Front val is " << t.readFront() << endl;
    t.display();

    t.dequeue();
    cout << " Front val is " << t.readFront() << endl;
    t.display();

    t.dequeue();
    cout << " Front val is " << t.readFront() << endl;
    t.display();
}