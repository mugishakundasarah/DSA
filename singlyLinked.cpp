#include <iostream>
using namespace std;

class StringNode{
    private:
        string elem;
        StringNode* next;
        friend class StringLinkedList;
};

class StringLinkedList{ 
    private:
        StringNode* head;
    public:
        StringLinkedList(){
            head = NULL;
        }

        int isEmpty(){
            if (head == NULL)
            {
                return 1;
            }
            return 0;
        }

        
    void addToFront(string data){
        StringNode* newNode;
        if (isEmpty())
        {
            cout << "Its empty at first " << endl;
            newNode->elem = data;
            newNode->next = NULL;
            head = newNode;
            return;
        }
        newNode->elem = data;
        newNode->next = head;
        head = newNode;
    }    

    void display(){
        StringNode* temp = head;
        int i = 0;
        while (temp != NULL)
        {
            cout << "The " << i << "th element is " << temp->elem << endl;
            temp = temp->next;
            i++;
        }
    }

    void traverseList(){
        if (isEmpty())
        {
            return;
        }
        StringNode* temp = head->next;
        
    }
};

int main(){
    StringLinkedList list1;
    list1.addToFront("sarah");
    list1.display();
}