#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct treeNode {
    int num;
    struct treeNode* leftChild;
    struct treeNode* rightChild;
}TreeNode;

TreeNode* createTreeNode(int num){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode -> num = num;
    newNode -> leftChild = NULL;
    newNode -> rightChild = NULL;
    return newNode;
}

void insertTreeNode(TreeNode** currentNode, TreeNode** newNode){
    if( (*newNode) -> num <= (*currentNode) -> num ){
        if( (*currentNode) -> leftChild == NULL )
            (*currentNode) -> leftChild = (*newNode);
        else
            insertTreeNode( &( (*currentNode) -> leftChild), &(*newNode) );
    }
    else{
        if( (*currentNode) -> rightChild == NULL)
            (*currentNode) -> rightChild = (*newNode);
        else
            insertTreeNode( &( (*currentNode) -> rightChild), &(*newNode) );  
    }
}

void preorderTraversal(TreeNode** currentNode){
    if( (*currentNode) == NULL )
        return;
    printf("%d ", (*currentNode)->num );
    preorderTraversal( &( (*currentNode) -> leftChild ));
    preorderTraversal( &( (*currentNode) -> rightChild ));
}

void inorderTraversal(TreeNode** currentNode){
    if( (*currentNode) == NULL )
        return;
    inorderTraversal( &( (*currentNode) -> leftChild ));
    printf("%d ", (*currentNode) -> num);
    inorderTraversal( &( (*currentNode) -> rightChild ));
}

void postorderTraversal(TreeNode** currentNode){
    if( (*currentNode) == NULL )
        return;
    postorderTraversal( &( (*currentNode) -> leftChild ));
    postorderTraversal( &( (*currentNode) -> rightChild ));
    printf("%d ", (*currentNode) -> num);
}

int main(int argc, char* argv[]){

    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    TreeNode* root = NULL;
    if(sizeof(arr) > 0)
        root = createTreeNode(arr[0]);
    TreeNode* newNode = NULL;
    int i = 1;
    for(; i<sizeof(arr)/sizeof(*arr); i++){
        newNode = createTreeNode(arr[i]);
        insertTreeNode(&root, &newNode);
    }
    printf("preorderTraversal:\n");
    preorderTraversal(&root);
    printf("\ninorderTraversal:\n");
    inorderTraversal(&root);
    printf("\npostorderTraversal:\n");
    postorderTraversal(&root);

    return 0;
}