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
                return;
            }
            else{
                Node* temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
};

int main(){
    LinkedList list1;
    list1.addNewNode(5);
    list1.addNewNode(4);
    list1.addNewNode(6);
}