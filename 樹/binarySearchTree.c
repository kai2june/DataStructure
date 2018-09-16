#include<stdio.h>
#include<stdlib.h>

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
    if( (*currentNode) == NULL ){
        (*currentNode) = (*newNode);
        return;
    }

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

void levelorderTraversal(TreeNode* treeNodeQueue[], int top, int last){
    if( top == last + 1 && top != 0 || treeNodeQueue[0] == NULL)
        return;  
    if( treeNodeQueue[top] -> leftChild )
        treeNodeQueue[++last] = treeNodeQueue[top] -> leftChild;
    if( treeNodeQueue[top] -> rightChild )
        treeNodeQueue[++last] = treeNodeQueue[top] -> rightChild;
    printf("%d ", treeNodeQueue[top++] -> num);
    levelorderTraversal(treeNodeQueue, top, last);
}

int main(int argc, char* argv[]){

    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    TreeNode* root = NULL;
    TreeNode* newNode = NULL;
    TreeNode* treeNodeQueue[sizeof(arr)/sizeof(*arr)];
    
    int i = 0, j = 0;
    for(; i<sizeof(arr)/sizeof(*arr); i++){
        newNode = createTreeNode(arr[i]);
        insertTreeNode(&root, &newNode);
        treeNodeQueue[i] = NULL;
    }
    if( root )
        treeNodeQueue[0] = root;
    
    printf("preorderTraversal:\n");
    preorderTraversal(&root);
    printf("\ninorderTraversal:\n");
    inorderTraversal(&root);
    printf("\npostorderTraversal:\n");
    postorderTraversal(&root);
    printf("\nlevelorderTraversal:\n");
    i=0;
    levelorderTraversal(treeNodeQueue, i, j);

    return 0;
}