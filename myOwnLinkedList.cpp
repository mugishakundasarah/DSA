#include <iostream>
using namespace std;

class Node{
    int data;
    Node *next;
    Node *head;
    public: 
        Node(){
            head->next = NULL;
            head = NULL;
        }
        Node(int value) {
            data = value;
            next = NULL;
        }
};

class LinkedList{
    Node *head;
    LinkedList(int headData){
        
    }
};

int main(){

}