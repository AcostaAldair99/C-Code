#include<stdio.h>
#include<stdlib.h>



//Struct to store the nodes values
struct node{
    int value;
    struct node *nextNode;
};

typedef struct node Node;


//Operations in the linked list 
Node * createNode(int value);
void push(Node **head,int value);
void pop(Node **head);
void display(Node **head);
void popInFront(Node **head);
void pushInFront(Node **head,int value);
void pushInIndex(Node **head,int index);
int getValueInIndex(Node **head,int index);
int getIndexInValue(Node **head,int value);
void popValue(Node **head,int value);
unsigned int getLength(Node **head);
Node * reverse(Node **head);


int main(){
    Node *head,*newHead;
    printf("The lenght is: %d\n",getLength(&head));
    push(&head,10);
    push(&head,11);
    push(&head,12);
    push(&head,13);
    push(&head,14);
    printf("The lenght is: %d\n",getLength(&head));
    display(&head);
    newHead = reverse(&head);
    display(&newHead);
}



Node * createNode(int value){
    Node *ptrNode = (Node*)malloc(sizeof(Node));
    ptrNode->nextNode = NULL;
    ptrNode->value = value;
    return ptrNode;
}


void push(Node **head,int value){
    Node *new,*current;
    new = createNode(value);
    if(*head == NULL){
        *head = new;
        return;
    }
    current = *head;
    
    while(current->nextNode != NULL){
       current = current->nextNode; 
    }
    current->nextNode = new;
    return;
}


void pop(Node **head){
    Node *current,*prev;
    if(*head == NULL){
        printf("The list is empty !!\n");
        exit(EXIT_FAILURE);
    }

    current = *head;
    while(current->nextNode != NULL){
        prev = current;
        current = current->nextNode;
    }

    prev->nextNode = NULL;
    free(current);

}

void popValue(Node **head,int value){
    Node *current,*prev,*next;
    if(*head == NULL){
        printf("The list is empty !!\n");
        exit(EXIT_FAILURE); 
    }
    current = *head;
    
    if(current->value == value){
        popInFront(head);
        return;
    }

    while(current->nextNode != NULL){
        if(value == current->value){
            break;
        }
        prev = current;
        current = current->nextNode;
    }
    next = current->nextNode;
    prev->nextNode = next;
    free(current);
}


void pushInFront(Node **head,int value){
    Node *new;
    new = createNode(value);
    if(*head == NULL){
        *head = new;
    }
    
    new->nextNode = *head;
    *head = new;
}

int getValueInIndex(Node **head,int index){
    Node *current;
    if(*head == NULL){
        printf("The list is empt\n");
        return -1;
    }
    current = *head;
    int i = 0;
    while(current != NULL){
        if(i == index){
            return current->value;
        }
        current = current->nextNode;
        i++;
    }
    return 0;    
}

int getIndexInValue(Node **head,int value){
     Node *current;
    if(*head == NULL){
        printf("The list is empt\n");
        return 0;
    }
    current = *head;
    int i = 0;
    while(current != NULL){
        if(value == current->value){
            return i;
        }
        current = current->nextNode;
        i++;
    }
    return -1; 
}



void popInFront(Node **head){
    Node *current;
    if(*head == NULL){
        printf("The list is empty !!\n");
        exit(EXIT_FAILURE);
    }
    current = *head;
    *head = current->nextNode;
    free(current);
}




void display(Node **head){
    Node *current;
    current = *head;

    while(current != NULL){
        printf("%d - ",current->value);
        current = current->nextNode;
    }
    printf("\n");
}

unsigned int getLength(Node **head){
    Node *current;
    unsigned int i = 0;
    if(*head == NULL){
        return i;
    }
    current = *head;
    while(current != NULL){
        i++;
        current = current->nextNode;
    }
    return i;
}

Node * reverse(Node **head){
    Node *current,*prev,*next;
    prev = NULL;
    if(*head == NULL){ 
        printf("The list is empty\n");
        exit(EXIT_FAILURE);
    }
    current = *head;
    while(current != NULL){
        next = current->nextNode;
        current->nextNode = prev;
        prev = current;
        current = next;
    }
    return prev;
}

