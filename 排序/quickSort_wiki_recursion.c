#include<stdio.h>

void swap(int *a, int *b){
    int tmp = (*a);
    (*a) ^= (*a) ^ (*b);
    (*b) ^= tmp ^ (*b);
}

void quickSort_recursion(int arr[], int start, int end){
    if(start >= end)
        return;
    int pivot = end, left = start, right = end-1;
    while( left < right ){
        while( arr[left] < arr[pivot] && left < right )
            left++;
        while( arr[right] >= arr[pivot] && left < right )
            right--;
        swap(&arr[left], &arr[right]);
    }
    if( arr[left] > arr[pivot] )
        swap(&arr[left], &arr[pivot]);
    else
        left++;
    quickSort_recursion(arr, start, left-1);
    quickSort_recursion(arr, left+1, end);

}

int main(int argc, char* argv[]){

    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    //int arr[] = { 22,34,3,32,1};
    int sorted[] = { 3, 5, 9, 22, 32, 34, 35, 37, 50, 55, 64, 70, 82, 89 };
    int i=0;
    for(i=0; i < sizeof(sorted)/sizeof(*sorted); i++)
        printf("%d ", sorted[i]);
    printf("\n");
    for(i=0; i<sizeof(arr)/sizeof(*arr); i++)
        printf("%d ", arr[i]);
    printf("\n\n");
    
    quickSort_recursion(arr, 0, sizeof(arr)/sizeof(*arr) -1 );
    printf("\n");
    for(i=0; i < sizeof(arr)/sizeof(*arr); i++)
        printf("%d ", arr[i]);

    return 0;
}