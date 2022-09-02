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

//isBST() method for check whether a tree in Binary Search Tree or Not!
int isBST(node* root){
    static node* prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

node* search(node* root, int key){
    if(root==NULL){
        return NULL;
    }
    else if(root->data==key){
        return root;
    }
    else if(root->data>key){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}

int main(){

    // Constructing the root node - Using Function (Recommended)
    node * p = createNode(5);
    node * p1 = createNode(3);
    node * p2 = createNode(6);
    node * p3 = createNode(1);
    node * p4 = createNode(4);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // printf("Printing preorder tree elements: \n");
    // preOrderTraverse(p);

    // printf("\nPrinting postorder tree elements: \n");
    // postOrderTraverse(p);

    // printf("\nPrinting inorder tree elements: \n");
    // inOrderTraverse(p);

    // if(isBST(p)){
    //     printf("\nIt is BST\n");
    // }
    // else{
    //     printf("It is not BST\n");
    // }

    node* n = search(p, 6);

    if(n!=NULL){
        printf("Found: %d", n->data);
    }
    else{
        printf("Element not found!");
    }
    
    return 0;
}