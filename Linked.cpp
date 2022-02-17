#include <iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;
};

class LinkedList{
    public:
        Node* head;
        LinkedList(){
            head = NULL;
        }

        void addNewNode(int data){
            Node* newNode;
            newNode->data = data;
            newNode->next = NULL;

            if (head == NULL)
            {
                head = newNode;
            }
        }
};

int main(){
    LinkedList list1;
}