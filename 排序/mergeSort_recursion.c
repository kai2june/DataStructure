#include<stdio.h>

void mergeSort_recursion(int arr[], int reg[], int start, int end){
    if(start >= end)
        return;
    int mid = (start+end) >> 1;
    int start1 = start, end1 = mid;
    int start2 = mid+1, end2 = end;
    mergeSort_recursion(arr, reg, start1, end1);
    mergeSort_recursion(arr, reg, start2, end2);
    int k= start;
    while(start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while(start1 <= end1)
        reg[k++] = arr[start1++];
    while(start2 <= end2)
        reg[k++] = arr[start2++];
    for(k=start; k<=end; k++)
        arr[k] = reg[k];
}

int main(int argc, char* argv[]){
    int arr[] = { 22, 34, 3, 18, 31, 293, 19, 29, 9, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 }; 
    int reg[sizeof(arr)/sizeof(*arr)];
    mergeSort_recursion(arr, reg, 0, sizeof(arr)/sizeof(*arr)-1);
    int i=0;
    for(i=0; i<sizeof(arr)/sizeof(*arr); i++)
        printf("%d ", arr[i]);

    return 0;
}