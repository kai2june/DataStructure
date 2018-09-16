#include<stdio.h>

void insertionSort(int arr[], int length){
    int i, j, tmp;
    for(i = 1; i < length; i++){
        tmp = arr[i];
        for( j = i; j >= 1 && arr[j-1] > tmp; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
}

int main(int argc, char* argv[]){
    
    int arr[] = {69, 57, 41, 28, 24, 13, 9};
    int length = 7;
    insertionSort(arr, length);
    int i = 0;
    for(i=0; i<length; i++){
        printf("%d ", arr[i]);
    }
        

    return 0;
}