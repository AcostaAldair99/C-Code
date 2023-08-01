#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define INDENT 1

struct node{
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node Node;


Node * createNode(int value);
Node * addNode(Node *root,int value);
void displayTree(Node *root,int indent);
void printIndent(int indent);
void display(Node *root);
Node * searchInTree(Node *root,int search);
Node * deleteNode(Node *root, int value);
Node *findMin(Node *root);
Node *findMax(Node *root);
void deallocateTree(Node **root);
bool isLeaf(Node *node);

int main(){
    Node *root = createNode(15);

    addNode(root,19);
    addNode(root,8);
    addNode(root,9);
    addNode(root,6);
    addNode(root,16);
    addNode(root,4);  
    addNode(root,3);  

    display(root);
    
    Node *s = searchInTree(root,4);
    printf("\n%p -> %d\n",s,s->value);

    root = deleteNode(root,4);
    root = deleteNode(root,16);   
    display(root);

    deallocateTree(&root);

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


Node * addNode(Node *root,int value){
    if(root == NULL){
        return createNode(value);
    } 
    
    if(value < root->value){
        root->left = addNode(root->left,value);
    }else if(value > root->value){
        root->right = addNode(root->right,value);
    }

    return root;
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

        // A node with one children (left or right)
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

