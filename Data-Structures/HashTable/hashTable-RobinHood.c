//Here we use the Robin Hood algorithm to avoid collisions
//between elements in the hash table
#include<stdio.h>
#include<stdlib.h>

#define SIZE 10 


typedef struct item{
    int value;
    int offset;
}Item;



Item * createItem(int value);
void addItem(Item *ht,int value);
void display(Item *ht);
void setSlot(Item *ht,Item *newItem,int offset);



int main(){
    Item *ht = (Item*)malloc(SIZE * sizeof(Item));

    addItem(ht, 11);
    addItem(ht, 12);
    addItem(ht, 13);
    addItem(ht, 12);
    addItem(ht, 19);
    display(ht);
}

Item * createItem(int value){
    Item *i = (Item*)malloc(sizeof(Item));
    if(i == NULL){
        return NULL;
    }
    i->value = value;
    i->offset = 0;
    return i;
}

void addItem(Item *ht,int value){
    
}

void setSlot(Item *ht,Item *newItem ,int hashIndex){
    if(ht[hashIndex].value != newItem->value){
        if(ht[hashIndex].offset < newItem->offset){
            Item *temp = createItem(ht[hashIndex].value,ht[hashIndex].offset);
            ht[hashIndex].value = 
        }
        return;
    }
    setSlot(ht,newItem,hashIndex+1);
    
}


void display(Item *ht){
    for(int i=0;i<SIZE;i++){
        printf("Value: %d - Offset: %d\n",ht[i].value,ht[i].offset);
    }
}

