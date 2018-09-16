#include<stdio.h>
#include<stdbool.h>

void bubbleSort(int arr[], int length){
    int i=0, j=0, temp=0;
    bool exchanged = true;
    for( i = 0; i < length - 1; i++){
        exchanged = false;
        for( j = 0; j < length - 1 - i; j++){
            if( arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                exchanged = true;
            }
        }
    }
}

int main(int argc, char* argv[]){
    
	int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
	int length =  sizeof(arr) / sizeof(*arr);
    bubbleSort(arr, length);
    int i = 0;
    for(i=0; i<length; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}