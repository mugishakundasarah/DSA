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
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
}
int main(){
    push(3);
    push(6);
    push(9);
    push(10);
    push(71);

    display();
    pop();
    display();
    cout << "The current element is " << pick() << endl;
}














