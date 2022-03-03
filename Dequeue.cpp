#include <iostream>
#define MAX 100
using namespace std;

class Dequeue{
    public: 
        int rear; 
        int front;
        int size; 
        int dequeue[MAX];

    public: 
        Dequeue(int size){
            this->rear = -1;
            this->front = -1;
            this->size = size;
        }

        bool isEmpty(){
            if(front == -1)
                return true;
            return false;
        }

        bool isFull(){
            if ((front == 0 && rear == size - 1) || (front == rear+1))
            {
                return true;
            }
            return false;
        }

        void addToFront(int data){
            if(isFull()){
                cout << "Queue overflow " << endl;
            }

            if (isEmpty())
            {
                front = 0;
                rear = 0;
            }else if(front == 0){
                front = size - 1;
            }else{
                front = front - 1;
            }
            dequeue[front] = data;
        }

        void addAtRear(int data){
            if(isFull()){
                cout << "Stack overflow " << endl;
                return;
            }
            if(isEmpty()){
                front = 0;
                rear = 0;
            }else if(rear == size - 1){
                rear = 0;
            }else{
                rear++;
            }
            dequeue[rear] = data;
        }
        void deleteFromFront(){
            if(isEmpty()){
                cout << "Queue underflow " << endl;
                return;
            }
            if(front == rear){
                front == -1;
                rear == -1;
            }else if(front == size-1){
                front = 0;
            }else{
                front++;
            }
        }
        void deleteFromRear(){
            if(isEmpty()){
                cout << "Queue underflow ";
                return;
            }
            if (front == rear)
            {
                front = rear = -1;
            }else if(rear == 0){
                rear = size - 1;
            }
            else{
                rear --;
            }
            
        }
        void display(){
            if(front > rear){
                cout << "front is " << front << endl;
                cout << "rear is " << rear << endl;
                for (int i = front; i < size; i++)
                {
                    cout << dequeue[i] << endl;
                }

                for (int j = 0; j <= rear; j++)
                {
                    cout << dequeue[j] << endl;
                }
            }
            else{
                cout << "front is " << front << endl;
                cout << "rear is " << rear << endl;
                for (int k = front; k <= rear; k++)
                {
                    cout << dequeue[k] << endl;
                }
            }
            
        }
}; 

int main(){
    Dequeue queue(10);
    queue.addAtRear(30);
    queue.addAtRear(31);
    queue.addAtRear(32);
    queue.addAtRear(33);
    queue.addAtRear(34);
    queue.display();
    queue.deleteFromFront();
    queue.display();
    queue.addToFront(55);
    queue.display();
    queue.addToFront(60);
    queue.display();
}