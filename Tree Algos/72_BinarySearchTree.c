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

node* searchIter(node* root, int key){
    while(root!=NULL){
        if(root->data == key){
            return root;
        }
        else if(root->data > key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

void insert(node* root, int key){
    node* prev = NULL;
    while(root!=NULL){
        prev = root;
        if(root->data==key){
            printf("Cannot insert %d, already in this tree", key);
            return;
        }
        else if(root->data>key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    node* new = createNode(key);
    if(prev->data>key){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

node* inOrderPredecessor(node* root){
    root = root->left;
    while(root->right!=NULL){
        root = root->right;
    }
    return root;
}

//Creating delete() funtion to delete the element from the tree
node* deleteNode(node* root, int value){
    node* inPre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    //Searching for the node to be deleted
    if(value<root->data){
        root->left = deleteNode(root->left, value);
    }
    else if(value>root->data){
        root->right = deleteNode(root->right, value);
    }
    //Deletion strategy when the node is found
    else{
        inPre = inOrderPredecessor(root);
        root->data = inPre->data;
        root->left = deleteNode(root->left, inPre->data);
    }
    return root;
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

    // node* n = searchIter(p, 6);

    // if(n!=NULL){
    //     printf("Found: %d", n->data);
    // }
    // else{
    //     printf("Element not found!");
    // }

    //Calling insert() funtion to insert the new element in the tree
    // insert(p, 8);
    // printf("%d", p->right->right->data);
    
    inOrderTraverse(p);
    //Calling delete() funtion to delete the element from the tree
    deleteNode(p, 6);
    printf("\n");
    inOrderTraverse(p);

    return 0;
}