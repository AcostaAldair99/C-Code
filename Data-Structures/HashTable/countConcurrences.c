//This code is for count the number of concurrences of a character in a string
//all start very well but added code that for me is very bad xd
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct node{
    char character;
    int concurrence;
}Node;

#define TABLE_SIZE 95 

unsigned int * allocateArray(unsigned int size);
void display(Node *array,unsigned int size);
Node *allocateAlphabet(unsigned int size);
void sortArray(Node *array,int size);
void setAlphabet(unsigned int *ht,Node *alphabet);
void swap(Node *a,Node*b);

int main(){
    char *data = "thissssiibb  biengenindos";
    unsigned int *ht = allocateArray(TABLE_SIZE);
    unsigned int hashIndex;

    while(*data != '\0'){
        hashIndex = *data - ' ';
        ht[hashIndex]++; 
        data++;
    }
    
    unsigned int size = 0; 
    for(int i = 0;i<TABLE_SIZE;i++){
        if(ht[i]>0){
            size++;
        }
    }
    Node *alphabet = allocateAlphabet(size);
    setAlphabet(ht,alphabet);
    free(ht);
    
    display(alphabet,size);
}

unsigned int * allocateArray(unsigned int size){
    unsigned int *array = (unsigned int*)malloc(sizeof(int)*size);
    if(array == NULL){
        return NULL;
    }
    return array;
}

void display(Node *array,unsigned int size){
    printf("Alphabet: \n");
    for(int i = 0; i<size;i++){
        printf("%c - [%d]\n",array[i].character,array[i].concurrence);
    }
}

Node *allocateAlphabet(unsigned int size){
    Node *a = (Node*)malloc(sizeof(Node)*size);
    if(a == NULL){
        return NULL;
    }
    return a;
}

void sortArray(Node array[],int size){
    bool isUnsorted = true;
    while(isUnsorted){
        int movements = 0 ; 
        for(int i=0;i<(size+1);i++){
            if(array[i].concurrence > array[i+1].concurrence){
                Node temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                movements++;
            }
        }
        if(movements == 0 ){
            isUnsorted = false;
        }else{
            isUnsorted = true;
        }

    }

}

void setAlphabet(unsigned int *ht,Node *alphabet){ 
    for(int i = 0,j=0;i<TABLE_SIZE;i++){
        if(ht[i]>0){
            // printf("%c - [%d]\n",i+32,ht[i]);
            alphabet[j].character = i+32;
            alphabet[j].concurrence = ht[i];
            j++;
        }
    }

}

void swap(Node *a,Node *b){
    Node *temp = a;
    a = b;
    b = temp;
}
