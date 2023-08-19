//In this versión use more features of reccursion
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "binaryTree.h"

#define INDENT 2

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


Node * addNode(Node **root,int value){
    if(*root == NULL){
        *root = createNode(value);
        return *root;
    } 
    
    if(value < (*root)->value){
        (*root)->left = addNode(&(*root)->left,value);
    }else if(value > (*root)->value){
        (*root)->right = addNode(&(*root)->right,value);
    }

    return *root;
}

Node * deleteNode(Node *root,int value){
    if(root ==  NULL ){
        return NULL;
    }
    
    if(value < root->value){
        root->left = deleteNode(root->left,value);
    }else if(value > root->value){
        root->right = deleteNode(root->right,value);
    }else{

        // Found the node to delete but have one children (left or right) , first check if is a leaf to deleted
        if(isLeaf(root)){ 
            free(root);
            return NULL;
        }else if(root->left == NULL || root->right == NULL){
            Node *temp;
            if(root->left == NULL){
                temp = root->right;
            }else{
                temp = root->left;
            }
            free(root);
            return temp;
        }
        
        //A node with two children
        else{
            Node *temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right,temp->value);
        }

    }

    return root;
}


Node * searchInTree(Node *root,int search){
    if(root ==  NULL || root->value == search){
        return root;
    } 

    if(search > root->value){
        return searchInTree(root->right,search);
    }else{
        return searchInTree(root->left,search);
    }
}



void display(Node *root){
    printf("\n--Display Tree--\n\n");
    displayTree(root,0);
}

void displayTree(Node *root,int indent){
    if(root != NULL){
        displayTree(root->right,indent+INDENT);
        if(indent > 0){
            printIndent(indent);  
        }
        printf("%d\n",root->value);
        displayTree(root->left,indent+INDENT);
    }

}

void printIndent(int indent){
    for(int i=0;i<indent;i++){
        printf("\t");
    }
}


Node * findMin(Node*root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node * findMax(Node *root){
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

void deallocateTree(Node **root){
    if(*root != NULL){
        deallocateTree(&(*root)->left);
        deallocateTree(&(*root)->right);
        free(*root);
    }
}


bool isLeaf(Node *node){
    if(node->left == NULL && node->right == NULL){
        return true;
    }
    return false;
}

bool isParent(Node *node){
    if(node->left !=NULL && node->right != NULL){
        return true;
    }
    return false;
}

