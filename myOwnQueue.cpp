#include <iostream>
using namespace std;

class Queue{
    public:
    int head, rear, *queue, capacity;
    Queue(int n){
        head = 0, rear = 0;
        capacity = n;
    }

    void checkEmpty(){
        if(rear == 0){
            cout << "The queue is empty " << endl;
            return;
        }
    }
    int checkFull(){
        if(rear == capacity){
            return 1;
        }
        return 0;
    }
    void enqueue(int data){
        if(checkFull()){
            cout << "The queue is full " << endl;
            return;
        }
        queue[rear] = data;
        cout << "added " << data << endl;
        rear++;
    }

    void dequeue(){
        checkEmpty();
        for (int i = 0; i < rear; i++)
        {
            queue[i] = queue[i+1];
        }
        rear--;
    }

    void display(){
        checkEmpty();
        for (int i = 0; i < rear; i++)
        {
            cout << queue[i] << endl;
        }
    }

    void front(){
        checkEmpty();
        cout << queue[head] << endl;
    }
};

int main(){
    Queue queue1(10);
    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(3);
    queue1.enqueue(4);
    queue1.enqueue(5);
    queue1.enqueue(6);
    queue1.enqueue(7);
    queue1.enqueue(8);
    queue1.enqueue(9);
    queue1.enqueue(10);
    queue1.enqueue(2);
    // queue1.display();
}