#include <iostream>
using namespace std;

void countDown(int i){
    cout << i << endl;
    if (i<=0){
        // Base case
        return;
    }
    else{
        // Recursive case
        countDown(i-1);
    }
}

int main(){
    countDown(5);
}