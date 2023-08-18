#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define SIZE 10 

int hashMultMethod(int value);
int hashModMethod(int value);
int search(int *array,int value);
int getIndex(int value);
void addToArray(int *array ,int value);
void addItem(int *array,int value,int hashIndex);
int * createArray();
void display(int *array);

int main(){
    int *array = createArray();
    
    addToArray(array,15);
    addToArray(array,13);
    addToArray(array,12);
    addToArray(array,19);
    addToArray(array,15);
    addToArray(array,15);
    addToArray(array,15);
    addToArray(array,15);
    addToArray(array,10);
    addToArray(array,10);        
    addToArray(array,10);
    addToArray(array,10);
    display(array);
}


int * createArray(){
    int *array = (int*)malloc(sizeof(int)*SIZE);
    if(array == NULL){
        return NULL; 
    }
    return array;
}

int getIndex(int value){
    return value%10;
}

//Using the mod method for hashing
int search(int *array,int value){
    return array[value % SIZE]; 
}

//Using the mod method for hashing
void addToArray(int *array,int value){
    //Here we try to handle collisions using Open Addressing 
    addItem(array,value,value%SIZE); 
}

void addItem(int *array,int value,int hashIndex){
    if(array[hashIndex] == 0 ){
        array[hashIndex] = value; 
        printf("We add the value: %d\n",value);
        return ;
    }
    if(hashIndex == (SIZE-1)){
        printf("There is not slots available!!\n");
        return;
    }
    addItem(array,value,hashIndex+1);
}

void display(int *array){
    printf("\n");
    for(int i=0;i<SIZE;i++){
        printf("%d - ",array[i]);
    }
    printf("\n");
}
