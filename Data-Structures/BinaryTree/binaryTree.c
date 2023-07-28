#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define INDENT 1

struct node{
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node Node;


Node * createNode(int value);
void addNode(Node **root,int value);
void displayTree(Node **root,int indent);
void printIndent(int indent);
void display(Node **root);

int main(){
    Node *root = NULL;

    addNode(&root,10);
    addNode(&root,1);
    addNode(&root,12);
    addNode(&root,13);
    addNode(&root,2);
    addNode(&root,11);
    addNode(&root,0);  
    addNode(&root,3);  

    display(&root);

}



Node * createNode(int value){
    Node *n = (Node*)malloc(sizeof(Node));
    if(n != NULL){
        n->value = value;
        n->left = NULL;
        n->right = NULL;
    }else{
        free(n);
        exit(EXIT_FAILURE);
    }
   return n;
}


void addNode(Node **root,int value){
    Node *newNode;
    newNode = createNode(value);
    if(*root == NULL){
        *root = newNode;
        return;
    }
    
    if((*root)->value > newNode->value){
        addNode(&(*root)->right,value);
    }else if((*root)->value < newNode->value){
        addNode(&(*root)->left,value);
    }else{
        printf("This value [ %d ] is already in the tree !!\n\n",(*root)->value);
        return;
    }
}

void display(Node **root){
    displayTree(root,0);
}


void displayTree(Node **root,int indent){
    if(*root != NULL){
        displayTree(&(*root)->left,indent+INDENT);
        if(indent > 0){
            printIndent(indent);  
        }
        printf("%d\n",(*root)->value);
        displayTree(&(*root)->right,indent+INDENT);
    }

}

void printIndent(int indent){
    for(int i=0;i<indent;i++){
        printf("\t");
    }
}


