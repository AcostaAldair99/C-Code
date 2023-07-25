#include<stdio.h>
#include<stdlib.h>



//Struct to store the nodes values
struct node{
    unsigned int value;
    struct node *nextNode;
    struct node *prevNode;
};

typedef struct node Node;


//Operations in the linked list 
Node * createNode(unsigned int value);
void push(Node **head,unsigned int value);
void pop(Node **head);
void display(Node **head);
void popInFront(Node **head);
void pushInFront(Node **head,unsigned int value);
void pushInIndex(Node **head,int index);
int getValueInIndex(Node **head,int index);
int getIndexInValue(Node **head,int value);
void popValue(Node **head,int value);

int main(){
    Node *head = NULL;
    push(&head,10);
    push(&head,11);
    push(&head,12);




    
    display(&head);
}


Node * createNode(unsigned int value){
    Node *pt = (Node*)malloc(sizeof(Node*));
    pt->value = value;
    pt->prevNode = NULL;
    pt->nextNode = NULL;
    return pt;
}


void push(Node **head,unsigned int value){
    Node *new,*current,*prev;
    new = createNode(value);
    if(*head == NULL){
        *head = new;
        return;
    }
    
    current = *head;
    
    while(current->nextNode !=  NULL){
        prev = current;
        current = current->nextNode;
    }
    new->prevNode = current;
    current->nextNode = new;
}


void display(Node **head){
    Node *current;
    current = *head;
    while(current != NULL){
        printf("\n%p\n-\n%d| %p\n-\n%p \n",current->prevNode,current->value,current,current->nextNode);
        current = current->nextNode;
    }
    printf("\n");
}

