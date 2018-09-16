#include<stdio.h>

void swap(int *a, int *b){
    int tmp = (*a) ^ (*b);
    (*a) ^= tmp;
    (*b) ^= tmp;
}

void selectionSort(int arr[], int length){
    int i=0, j=0, min=0; 
    for( i=0; i<length-1; i++){
        min=i;
        for(j=i;j<length; j++){
            if(arr[j] < arr[min])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
}

int main(int argc, char* argv[]){

	int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int length = sizeof(arr) / sizeof(*arr);
    selectionSort(arr, length);
    int i=0;
    for(i=0; i<length; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}