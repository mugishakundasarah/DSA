#include <iostream>
using namespace std;

const int length = 100;
int stack[length], top = -1;

void isFull(){
    if (top == length-1)
    {
        cout << "stack overflow " << endl;
        return;
    }
}
void push(){
    isFull();
    top++;
    stack[top] = top;
}
void pop(){
    
}
int main(){
}