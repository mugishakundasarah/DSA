#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class LinkedList{
    private:
        Node *head, *tail;
    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }
};

int main(){
    LinkedList a;
    return 0;
}