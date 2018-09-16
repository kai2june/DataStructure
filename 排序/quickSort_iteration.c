#include<stdio.h>

struct range {
    int start;
    int end;
};

struct range newRange(int start, int end){
    struct range myRange;
    myRange.start = start;
    myRange.end = end;
    return myRange;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a ^= *a ^ *b;
    *b ^= tmp ^ *b;
}

void quickSort_iteration(int arr[], const int length){
    if(length <=1 )
        return;

    struct range r[length];
    int p=0;
    r[p++] = newRange(0, length-1);

    while(p){
        struct range myRange = r[--p];
        if(myRange.start >= myRange.end)
            continue;
        int pivot = arr[(myRange.start + myRange.end)/2];
        int left = myRange.start, right = myRange.end;
        do{
            while( arr[left] < pivot ) left++;
            while( arr[right] > pivot ) right--;
            
            if(left <= right){
                swap(&arr[left], &arr[right]);
                left++;
                right--;            
            }
        }while(left<=right);
    
        if( myRange.start < right ) r[p++] = newRange(myRange.start, right);
        if( myRange.end > left ) r[p++] = newRange(left, myRange.end);
    }
}

int main(int argc, char* argv[]){

    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    quickSort_iteration(arr, sizeof(arr)/sizeof(*arr));
    int i=0;
    for(i=0; i<sizeof(arr)/sizeof(*arr); i++)
        printf("%d ", arr[i]);

    return 0;
}