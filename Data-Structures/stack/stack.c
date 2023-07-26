//This is a implementation of a stack 
//with and dinamic size
#include<stdio.h>
#include<stdlib.h>


struct stack{
    unsigned int top;
    unsigned int capacity;
    int *data;
};

typedef struct stack Stack;

Stack * createStack(unsigned int capacity);
void push(Stack *stack,int value);
int peek(Stack *stack);
void pop(Stack *stack);
void display(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
unsigned int size(Stack *stack);

int main(){
    Stack *s1;
    s1 = createStack(3);
    push(s1,10);
    push(s1,12);
    push(s1,13);

    push(s1,14);
    display(s1);

}

void push(Stack *stack,int value){
    if(isFull(stack)){
        printf("The stack is full !!\n");
        return; 
    }else{
        stack->top++;
        stack->data[stack->top] = value;
    }
}

void pop(Stack *stack){
    if(!isEmpty(stack)){
        stack->data[stack->top] = 0;
        stack->top--;
    }else {
        printf("The stack is empty!!\n");
        return;
    }
}

int peek(Stack *stack){
    if(!isEmpty(stack)){
        return stack->data[stack->top]; 
    }
    return 0;
}

void display(Stack *stack){
     if(!isEmpty(stack)){
        printf("\nSize: %d - Capacity: %d\n",stack->top+1,stack->capacity);
        for(int i = (stack->top) ; i >= 0;i--){
            printf("\n%d\n__",*(stack->data+i));
        }
        printf("\n");
     }else{
         printf("The stack is empty!!\n");
     }
}


Stack * createStack(unsigned int capacity){
    Stack *st  = (Stack *) malloc(sizeof(Stack));
    st->top=-1;
    st->capacity = capacity;
    st->data = (int*) malloc( capacity * sizeof(int)); 
    return st;
}


int isEmpty(Stack *stack){
    if(stack->top == -1){
        return 1;
    } 
    return 0;
}

int isFull(Stack *stack){
    if((stack->capacity-1) == stack->top){
        return 1;
    }
    return 0;
}

unsigned int size(Stack *stack){
    return stack->top+1;
}

