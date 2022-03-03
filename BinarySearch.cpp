#include <iostream>
using namespace std;

int binary_search(int *arr, int arrSize, int searchItem){
    int low = 0;
    int high = arrSize - 1;
    int mid;
    int guess;
    int result = -1;

    while (low < high)
    {
        if((low + high) % 2 != 0  && high!=1){
            mid = (low + high + 1) / 2; 
        }
        else{
            mid = (low + high) / 2;
        }

        guess = arr[mid];
        
        if (guess == searchItem)
        {
            result = mid;
            break;
        }
        else if(guess > searchItem)
        {
            high = mid;    
        }
        else{
            low = mid;
        }
    }
    
    return result;
}

int main(){
    int myList[5] = {1,3,5,7,9};
    int res = binary_search(myList, 5, 9);

    if(res == -1){
        cout << "none" << endl;
    }

    else{
        cout << res << endl;
    }
    return 0;
    
}