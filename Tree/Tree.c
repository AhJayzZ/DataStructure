#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_AMOUNT 10

// ------------------------------------------------- Struct ------------------------------------------
// Node Struct 
typedef struct Node
{
    int value;
    struct Node *leftChild;
    struct Node *rightChild;
}Node;

// ------------------------------------------------- Random ------------------------------------------
// Random number generate
int *generateNumbers(int amount){
    srand(time(NULL));
    int *randomNum = malloc(sizeof(int)*amount);
    printf("Random Number:");
    for (int i=0;i<amount;i++){
        randomNum[i] = rand() % 100;
        printf("%d ",randomNum[i]);
    }
    printf("\n");
    return randomNum;
}


// ------------------------------------------------- Travelsal ------------------------------------------
// Inorder Travelsal
void inorderTravelsal(Node *root){
    if (root == NULL)
        return;
    else{
        inorderTravelsal(root->leftChild);
        printf("%d ",root->value);
        inorderTravelsal(root->rightChild);
    }
}

// Preorder Travelsal
void preorderTravelsal(Node *root){
    if (root == NULL)
        return;
    else{
        printf("%d ",root->value);
        preorderTravelsal(root->leftChild);
        preorderTravelsal(root->rightChild);
    }
}

// Postorder Travelsal
void postorderTravelsal(Node *root){
    if (root==NULL)
        return;
    else{
        postorderTravelsal(root->leftChild);
        postorderTravelsal(root->rightChild);
        printf("%d ",root->value);
    }
}

// ------------------------------------------------- Operation ------------------------------------------
// Create node
Node *newNode(int data){
    Node *node = malloc(sizeof(Node));
    node->value = data;
    node->leftChild = node->rightChild = NULL;
    return node;
}

// Insert node
Node *insertNode(Node *root,int data){
    if (root == NULL)
        return newNode(data);
    else{
        if (data < root->value)
            root->leftChild = insertNode(root->leftChild,data);
        else 
            root->rightChild = insertNode(root->rightChild,data);
    }
    return root;
}

// Search node
Node *searchNode(Node *root,int data){
    if (root == NULL){
        printf("Node NOT found");
        return NULL;
    } 
    else if (root->value == data){
        printf("Node found(value:%d address:%p)",root->value,root);
        return root; 
    }
    else{
        if (data < root->value)
            searchNode(root->leftChild,data);
        else
            searchNode(root->rightChild,data);
    }
}

// Delete Node
Node *deleteNode(Node *root,int data){
    if (root==NULL)
        return NULL;
    else if (data < root->value)
        deleteNode(root->leftChild,data);
    else if (data > root->value)
        deleteNode(root->rightChild,data);
    else{
        

    }
}   




// ------------------------------------------------- Main ------------------------------------------
// Main
int main(){
    //int *randomNum = generateNumbers(DATA_AMOUNT);
    int randomNum[DATA_AMOUNT] = {5,1,8,9,2,4,3,0,7,6};


    //  Build BST   
    Node *root = NULL; // Root
    for (int i=0;i<DATA_AMOUNT;i++)
        root = insertNode(root,randomNum[i]);
    
    //printf("Inorder:");
    //inorderTravelsal(root);
    //printf("Preorder:");
    //preorderTravelsal(root);
    // printf("Postorder:");
    // postorderTravelsal(root);
    Node *found = searchNode(root,2);
}