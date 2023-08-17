#include<stdio.h>
#include<stdlib.h>



#define SIZE 5 

int hashMultMethod(int value);
int hashModMethod(int value);
int search(int *array,int value);
int getIndex(int value);
void addToArray(int *array ,int value);
int * createArray();
void display(int *array);

int main(){
    int *array = createArray();
    
    for(int i = 0;i < SIZE;i++){
        addToArray(array,i+SIZE);
    }

    display(array);
    printf("Value Searched: %d\nIs in the Index: %d\n",search(array,14),getIndex(14));
    printf("\n%d:",5%10);
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
    return array[hashModMethod(value)]; 
}

//Using the mod method for hashing
void addToArray(int *array,int value){
    array[hashModMethod(value)] = value;
}


//Hashing with the mult method
int hashModMethod(int value){
    return value % SIZE; 
}



void display(int *array){
    printf("\n");
    for(int i=0;i<SIZE;i++){
        printf("%d - ",array[i]);
    }
    printf("\n");
}
