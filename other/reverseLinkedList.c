#include<stdio.h>
#include<stdlib.h>

struct node{
    int num;
    struct node* next;
};

struct node* createNode(int num){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> num = num;
    newNode -> next = NULL;
    return newNode;
}

void insertNode(struct node** head, struct node** tail, struct node* newNode){
    if( (*head) == NULL )
        (*head) = (*tail) = newNode;
    else{
        (*tail) -> next = newNode;
        (*tail) = newNode;
    }
}

void printList(struct node** head){
    struct node* tmp = (*head);
    while( tmp != NULL){
        printf("%d ", tmp -> num);
        tmp = tmp -> next;
    }
}

void reverseList(struct node** head, struct node** tail){
    if( ((*head) == NULL) || (((*head) -> next) == NULL) )
        return;
    struct node* previous = NULL;
    struct node* current = (*head);
    struct node* preceding = (*head) -> next;
    (*tail) = (*head);

    while(current != NULL){
        preceding = current -> next;
        current -> next = previous;
        previous = current;
        current = preceding;
    }
    (*head) = previous;
}
int main(int argc, char* argv[]){
    struct node* head = NULL;
    struct node* tail = NULL;
    struct node* newNode = NULL;
    int count = 1;
    for(; count<=5; count++){
        newNode = createNode(count);
        insertNode(&head, &tail, newNode);
    }
    printList(&head);
    reverseList(&head, &tail);
    printList(&head);
    return 0; 
}