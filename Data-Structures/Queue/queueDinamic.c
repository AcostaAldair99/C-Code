//This is a implementation of a dinamic
//queue based in a linked list 

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include <sys/types.h>


typedef struct item{
   int value;
   struct item *pNext;
} Item; 


Item * createItem(int value);
void enqueue(Item **head,Item **tail,int value);
void dequeue(Item **head);
void dequeueTail(Item **head,Item **tail);
void display(Item **head,Item **tail);
int peek(Item **head);
int rear(Item **tail);


int main(){
    Item *head,*tail = NULL;
    
    enqueue(&head,&tail,10);
    enqueue(&head,&tail,12);   
    enqueue(&head,&tail,13);
    enqueue(&head,&tail,14);
    enqueue(&head,&tail,15);
 
    display(&head,&tail);

    dequeue(&head);

    display(&head,&tail);
    enqueue(&head,&tail,22);
    // dequeueTail(&head,&tail);
    display(&head,&tail);
    printf("\nThe peek result: %d\nThe rear result: %d\n",peek(&head),rear(&tail)); 

}

void dequeue(Item **head){
   Item *current; 
   if(*head == NULL){
        printf("The queue is empty !!\n");
       return;
   }
   current = *head; 
    *head = current->pNext;
    free(current);
    return;
}

void dequeueTail(Item **head,Item **tail){
    Item *current,*prev;
    if(*head == NULL){
        printf("The queue is empty !!\n");
        return;
    }
    current = *head;
    while(current->pNext != NULL){
        prev = current;
        current = current->pNext;
    }
     printf("Prev: %d - Current: %d\n",prev->value,current->value);
    *tail = prev;
    free(current);
    return;
}

void enqueue(Item **head,Item **tail,int value){
    Item *current,*new;
    new = createItem(value);
    if(*head ==  NULL){
        *head = new;
        *tail = new;
        return;
    }

    current = *head; 
    
    while(current->pNext !=  NULL){
        current = current->pNext;
    }
    current->pNext = new;
    *tail = new;
    return;
}
int peek(Item **head){
   if(*head == NULL){
       printf("The queue is empty !!\n");
       return -1;
   } 
   return (*head)->value;
}

int rear(Item **tail){
    if(*tail == NULL){
        printf("The queue is empty !!\n");
        return -1;
    }
    return (*tail)->value;
}

Item * createItem(int value){
   Item *item = (Item*)malloc(sizeof(Item));
   item->pNext = NULL; 
   item->value = value;
   return item; 
}


void display(Item **head,Item **tail){
    Item *current;
    current = *head;
    printf("\n->HEAD: %d -- TAIL: %d\n\n",(*head)->value,(*tail)->value);

    while(current != NULL){
        printf("%d - ",current->value);
        current = current->pNext;
    }
    printf("\n");
}


