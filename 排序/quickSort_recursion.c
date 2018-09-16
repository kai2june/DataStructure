#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a ^= *a ^ *b;
    *b ^= tmp ^ *b;
}

void quickSort_recursion(int arr[], int start, int end){
    if(start>=end)
        return;
    int pivot = end, left=start, right=end-1;
    while(left < right){
        while( arr[left] < arr[pivot] )
            left++;
        while( arr[right] > arr[pivot] && left < right)
            right--;
        if(left < right)
            swap(&arr[left],&arr[right]);
    }
    swap(&arr[left], &arr[pivot]);
    quickSort_recursion(arr, start, left-1);
    quickSort_recursion(arr, left+1, end);
}

int main(int argc, char* argv[]){

    int arr[] = { 22, 34, 3, 18, 31, 293, 19, 29, 9, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    quickSort_recursion(arr, 0, sizeof(arr)/sizeof(*arr)-1);
    int i=0;
    for(i=0; i<sizeof(arr)/sizeof(*arr); i++)
        printf("%d ", arr[i]);

    return 0;
}