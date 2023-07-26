//This is a implementation of a queue 
//with and dinamic size
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue{
    unsigned int current;
    unsigned int capacity;
    int *data;
};

typedef struct queue Queue;


Queue * createQueue(unsigned int capacity);
bool isEmpty(Queue *q);
bool isFull(Queue *q);
void enqueue(Queue *q, int value);
void display(Queue *q);
int dequeue(Queue *q);
int dequeueFront(Queue *q);


int main(){
   Queue *q = createQueue(3); 
    
   enqueue(q,1);
   enqueue(q,2);
   enqueue(q,3);
   enqueue(q,4);
   enqueue(q,5);
   //  
   // display(q);
   // int x = dequeue(q);
   // printf("The value dequeue: %d\n",x);
   // display(q);
   //int s = dequeue(q);
    
   int s = dequeueFront(q);
   printf("The value of front: %d\n\n",s);
   display(q);

}

int dequeueFront(Queue *q){
    int value;
    if(isEmpty(q)){
        printf("The queue is empty !!\n");
        return -1;
    }else{
        value = q->data[0];
        for(int i=0;i<q->current;i++){
            q->data[i] = q->data[i+1];
        }
        q->current--;
    }
    return value;
}


Queue * createQueue(unsigned int capacity){
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->current= -1;
    q->data = (int*)malloc(capacity*sizeof(int));
    return q;
}

void display(Queue *q){
    if(isEmpty(q)){
        printf("The queue is empty !!\n");
        return; 
    }else{
        printf("Capacity: %d - - Size: %d\n \n",q->capacity,q->current+1);
        for(int i=0;i<(q->current+1);i++){
            printf("%d - ",q->data[i]); 
        }
        printf("\n");
    }
}

bool isFull(Queue *q){
    if((q->capacity-1) == q->current){
        return true;
    }
    return false;
}

bool isEmpty(Queue *q){
    if(q->current == -1){
        return true;
    }
    return false;
}

void enqueue(Queue *q,int value){
    if(isFull(q)){
        printf("The queue is full !!\n");
        return;
    }else{
        q->current++;
        q->data[q->current] = value;
    }
}

int dequeue(Queue *q){
    int value;
    if(isEmpty(q)){
        printf("The queue is empty !!\n");
        return -1;
    }else{
        value = q->data[q->current];
        q->data[q->current] = 0;
        q->current--;
    }
    return value;
}
