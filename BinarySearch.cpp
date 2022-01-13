#include <iostream>
using namespace std;

int binary_search(int *arr, int arrSize, int searchItem){
    int low = 0;
    int high = arrSize - 1;
    int mid = (low + high) / 2;
    int guess = arr[mid];
    int result = -1;

    while (low <= high)
    {
        if (guess == searchItem)
        {
            result = mid;
        }
        else if(guess > searchItem)
        {
            high = mid;
            mid = (low + high) / 2; 
        }
        else{
            low = mid;
            mid = (low + high) / 2;
        }
    }
    
    return result;
}

int main(){
    
}