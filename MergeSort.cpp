#include <iostream>
using namespace std;


void print(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

/** Merge Sort Algorithm **/
void merge(int arr[] , int begin, int mid, int end){
    int sizeOfLeftArr = mid - begin+1;
    int sizeOfRightArr = end - mid; 
    int leftIndexCount = 0;
    int rightIndexCount = 0;
    int mergedIndexCount = begin;

    int leftArr[sizeOfLeftArr];
    int rightArr[sizeOfRightArr];

    for (int i = 0; i < sizeOfLeftArr; i++)
    {
        leftArr[i] = arr[begin + i];
    }

    for (int j = 0; j< sizeOfRightArr; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    /** Merge when both sub arr have elements **/
    while (leftIndexCount < sizeOfLeftArr && rightIndexCount < sizeOfRightArr){
        if(leftArr[leftIndexCount] <= rightArr[rightIndexCount]){
            arr[mergedIndexCount] = leftArr[leftIndexCount];
            leftIndexCount ++;
        }else{
            arr[mergedIndexCount] = rightArr[rightIndexCount];
            rightIndexCount ++;
        }
        mergedIndexCount++;
    }

    while (leftIndexCount < sizeOfLeftArr){
        arr[mergedIndexCount] = leftArr[leftIndexCount];
        leftIndexCount ++;
        mergedIndexCount ++ ;
    }

    while(rightIndexCount < sizeOfRightArr){
        arr[mergedIndexCount] = rightArr[rightIndexCount];
        rightIndexCount++;
        mergedIndexCount++;
    }
    cout << "After merge: " ;
    print(arr, mergedIndexCount);
    cout << endl;
}


void mergeSort(int arr[], int begin, int end){
    if (begin>=end)
    {
        return;
    }
    int mid = (begin + end)/2;
    cout << "Begin " << begin << " Mid " << mid << " End " << end << endl;   
    mergeSort(arr,begin, mid);
    cout << endl << endl;
    mergeSort(arr, mid + 1 , end);
    cout << " final merging " << endl;
    merge(arr, begin, mid, end);
}

int main(){
    int arr[] = {85, 24, 63, 45, 17, 31, 96, 50};
    int arrSize = 8;
    cout<< "Unsorted is : ";
    print(arr, arrSize);
    cout << endl;
    mergeSort(arr, 0, arrSize);
    print(arr, arrSize);
    cout << endl;
}