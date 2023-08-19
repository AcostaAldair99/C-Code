#include "binaryTree.h"
#include<stdio.h>





int main(){
    Node *root = NULL;

    addNode(&root, 20);
    addNode(&root, 10);
    addNode(&root, 22);
    addNode(&root, 21);
    addNode(&root, 5);
    addNode(&root, 6);
    
    display(root);
    
    Node * node = searchInTree(root,4);
    if (node != NULL){
        printf("The found the Node: %d\n",node->value);
    }else{
        printf("The Node was´nt found\n");
    }

}
