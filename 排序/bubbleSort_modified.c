#include<stdio.h>

void bubbleSort_modified(int arr[], int length){
    int i=0, last=0, current=0, tmp=0;
    for(last=length-1; last>0; last=current){
        current=0;
        for(i=0; i<last; i++){
            if(arr[i]> arr[i+1]){
                tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
                current = i;
            }
        }
    }
}

int main(int argc, char* argv[]){

    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int arr2[] = { 22, 34, 3, 32, 55, 50, 37, 5, 64, 35, 9, 70, 82, 89 };
    int length = sizeof(arr) / sizeof(*arr);
    bubbleSort_modified(arr, length);
    int i = 0;
    for( ; i<length; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}