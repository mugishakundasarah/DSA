#include <iostream>
using namespace std;

#define INT_MAX 2147483647
const int siz = 20;
int top = -1;
int stack[siz];
int isFull(){
    if(top == siz -1)
        return 1;    
    return 0;
}

int isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}


void push(int data) {
    if(!isFull()){
        top++;
        stack[top] = data;
    }else{
        cout << "stack overflow" << endl;
    }
}

void pop(){
    if(!isEmpty()){
        top--;
    }else{
        cout << "stack underflow" << endl;
    }
}

int pick(){
    if(!isEmpty())
        return stack[top];
    return INT_MAX;
}

void display(){
    if(!isEmpty()){
        cout << " The elements in the stack are: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << "\t";
        }
        cout << endl;
    }
    else{
        cout << "stack underflow" << endl;
    }
}
int main(){
    
    cout << " ######## WELCOME TO THE STACK PROGRAM ########## " << endl ;
    char answer = 'Y';
    int option;
    while (answer == 'Y')
    {
        cout << " SELECT BETWEEN THESE OPERATIONS: " << endl ;
        cout << " (1) for POP " ;
        cout << " (2) for PUSH  " ;
        cout << " (3) for PICK : ";
        cin >> option ;
        
        switch (option)
        {
            case 1:
                pop();
                display();
                break;
        
            case 2:
                cout << "input push value : ";
                int value;
                cin >> value;
                push(value);
                display();
                break;

            case 3:
                cout << pick() << endl;
                break;

            default:
                cout << "please choose among the given options" << endl;
                break;
        }

        cout << "do you want to continue?? (Y/N) : ";
        cin >> answer ;
    }
}














