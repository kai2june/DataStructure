#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int num;
    struct node* next;
} Node;

int count=0;
void swap(Node** first, Node** second){
    int tmp = (*first) -> num;
    (*first) -> num = (*second) -> num;
    (*second) -> num = tmp;
    // if( (count++) ==0)
    //     swap( &( (*first) -> next), &( (*second) -> next) );
    (count++) == 0 ? swap( &( (*first) -> next), &( (*second) -> next) ) : 0 ;
}

int main(int argc, char* argv[]){
    
    Node* first = (Node*)malloc(sizeof(Node));
    first -> num = 1;
    Node* second = (Node*)malloc(sizeof(Node));
    second -> num = 2;

    first -> next = second; 
    second -> next = first;

    printf("Before swap: first -> num = %d , second -> num = %d\n", first->num, second->num);
    swap(&first, &second);
    printf("After swap two times: first -> num = %d , second -> num = %d\n", first->num, second->num);

    return 0;
}