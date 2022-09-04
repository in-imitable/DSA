#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node* left;
    struct node* right;
    int height;
}node;

node* createNode(int key){
    node* n = (node*)malloc(sizeof(node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

void inOrderTraverse(node* root){
    if(root!=NULL){
        inOrderTraverse(root->left);
        printf("%d ", root->key);
        inOrderTraverse(root->right);
    }
}

// PreOrder function for Binary Tree
void preOrderTraverse(node* root){
    if(root!=NULL){
        printf("%d ", root->key);
        preOrderTraverse(root->left);
        preOrderTraverse(root->right);
    }
} 

int getHeight(node* n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

int getBalancedFactor(node* n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

int  max(int a, int b){
    return (a>b)?a:b;
}

// Declaring rightRotate() funtion
node* rightRotate(node* y){
    node* x = y->left;
    node* T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
} 

// Declaring leftRotate() funtion
node* leftRotate(node* x){
    node* y = x->right;
    node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
} 

//Declaring insert() function 
node* insert(node* n, int key){
    if(n==NULL){
        return createNode(key);
    }

    if(key<n->key){
        n->left = insert(n->left, key);
    }
    else if(key>n->key){
        n->right = insert(n->right, key);
    }

    n->height = 1+max(getHeight(n->left), getHeight(n->right));

    int bf = getBalancedFactor(n);

    //Left Left Case
    if(bf>1 && key<n->left->key){
        return rightRotate(n);
    }

    //Right Right Case
    if(bf< -1 && key>n->right->key){
        return leftRotate(n);
    }

    //Left Right Case
    if(bf>1 && key>n->left->key){
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

    //Right Left Case
    if(bf< -1 && key<n->right->key){
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    return n;
}

int main(){
    
    struct Node * root = NULL;
 
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preOrderTraverse(root);

    return 0;
}