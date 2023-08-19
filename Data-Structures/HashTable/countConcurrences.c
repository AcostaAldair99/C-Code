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
unsigned int * setHashTable(char *data);
unsigned int getAlphabetNumber(unsigned int *ht);

int main(){
    char *data = "thissssiibbs";
    unsigned alphabetSize;

    unsigned int *ht = setHashTable(data); 
    alphabetSize = getAlphabetNumber(ht);
    Node *alphabet = allocateAlphabet(alphabetSize);


    setAlphabet(ht,alphabet);
    free(ht);
    sortArray(alphabet, alphabetSize);
    display(alphabet,alphabetSize);
}

unsigned int * setHashTable(char *data){
    unsigned int hashIndex;
    unsigned int *ht = allocateArray(TABLE_SIZE);
    while(*data != '\0'){
        hashIndex = *data - ' ';
        ht[hashIndex]++; 
        data++;
    }
    return ht;
}

unsigned int getAlphabetNumber(unsigned int *ht){
    unsigned int size = 0;
    for(int i=0;i<TABLE_SIZE;i++){
        if(ht[i] > 0 ){
            size++;
        }
    }
    return size;
}

unsigned int * allocateArray(unsigned int size){
    unsigned int *array = (unsigned int*)malloc(sizeof(int)*size);
    if(array == NULL){
        return NULL;
    }
    return array;
}

void display(Node *array,unsigned int size){
    printf("Alphabet Size: %d \n",size);
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

void sortArray(Node *array,int size){
    int movements;
    bool isUnsorted = true;
    while(isUnsorted){
        movements = 0 ; 
        for(int i=0;i<(size-1);i++){
            if(array[i].concurrence > array[i+1].concurrence){
                Node temp = array[i+1];
                array[i+1] =  array[i];
                array[i] = temp;
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
