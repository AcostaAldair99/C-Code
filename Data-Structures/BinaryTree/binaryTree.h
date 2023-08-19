#ifndef BINARY_TREE
#define BINARY_TREE

#include <stdbool.h>
struct node{
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node Node;


Node * createNode(int value);
Node * addNode(Node **root,int value);
void displayTree(Node *root,int indent);
void printIndent(int indent);
void display(Node *root);
Node * searchInTree(Node *root,int search);
Node * deleteNode(Node *root, int value);
Node *findMin(Node *root);
Node *findMax(Node *root);
void deallocateTree(Node **root);
bool isLeaf(Node *node);

#endif
