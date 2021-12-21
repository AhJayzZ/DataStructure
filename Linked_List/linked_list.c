#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}Node;

Node* createNode(int);
Node* createNodes(int);
void showAllNode(Node*);
void insertNode(Node*,int,Node*);
void deleteNode(Node*,Node*);
Node* invert(Node*);

void main(){
Node *A = createNodes(5);
//Node *test = createNode(10);
//insertNode(A,5,test);
showAllNode(A);
A = invert(A);
showAllNode(A);
free(A);
}

void showAllNode(Node *head){
    while (head){
        printf("Address:%X Values:%d Next:%X\n",head,head->value,head->next);
        head = head->next;
    }
    printf("\n");
}

Node* createNodes(int N){
    Node *List = createNode(0);
    Node *ptr = List;
    for(int i = 0; i < N-1 ; i++){
        ptr->next = createNode(i+1);
        ptr = ptr->next;
    }
    return List;
}

Node* createNode(int value){
    Node *node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void insertNode(Node* nodeList,int insertPosition,Node* newNode){
    Node *temp = nodeList;
    int index = insertPosition;
    if (nodeList == NULL)
        printf("Nothing to insert");
    else{
        while (--index)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(Node* head,Node* deleteNode){
    Node *temp = head;
    if (temp == NULL)
        printf("Nothing to delete");
    
    if (deleteNode == head){
        head = head->next;
    }
    else{
        while (temp->next != deleteNode)
            temp = temp->next;
        temp->next = deleteNode->next; 
    }
    free(deleteNode);
}

Node* invert(Node* nodeList){
    Node *front = nodeList;
    Node *ptr = NULL;
    Node *rear;
    if (front == NULL)
        printf("Nothing to invert");
    else{
        while (front != NULL){
        rear = ptr;
        ptr = front;
        front = front->next;
        ptr->next = rear;
        }    
    }
    return ptr;
}