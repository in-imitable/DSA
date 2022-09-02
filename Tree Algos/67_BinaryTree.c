#include<stdio.h>
#include<stdlib.h>

// To define the structure of a tree 
typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;    
}node;


// This function creating the node for a tree
node * createNode(int data){
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

// PreOrder function for Binary Tree
void preOrderTraverse(node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrderTraverse(root->left);
        preOrderTraverse(root->right);
    }
} 

// PostOrder function for Binary Tree
void postOrderTraverse(node* root){
    if(root!=NULL){
        postOrderTraverse(root->left);
        postOrderTraverse(root->right);
        printf("%d ", root->data);
    }
}

// InOrder function for Binary Tree
void inOrderTraverse(node* root){
    if(root!=NULL){
        inOrderTraverse(root->left);
        printf("%d ", root->data);
        inOrderTraverse(root->right);
    }
}

int main(){

    // Constructing the root node - Using Function (Recommended)
    node * p = createNode(4);
    node * p1 = createNode(1);
    node * p2 = createNode(6);
    node * p3 = createNode(5);
    node * p4 = createNode(2);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Printing preorder tree elements: \n");
    preOrderTraverse(p);

    printf("\nPrinting postorder tree elements: \n");
    postOrderTraverse(p);

    printf("\nPrinting inorder tree elements: \n");
    inOrderTraverse(p);
    
    return 0;
}