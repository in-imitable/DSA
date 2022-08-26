#include<stdio.h>
#include<stdlib.h>
 
typedef struct Node{
    int data;
    struct Node * next;
}node;
 
node* top = NULL;
 
void linkedListTraversal(node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next; 
    }
    printf("\n");
}
 
int isEmpty(node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(node* top){
    node* p = (node*)malloc(sizeof(node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
node* push(node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        node* n = (node*) malloc(sizeof(node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
 
int pop(node* top){
    if(isEmpty(top)){
        printf("Stack Underflow\n");
    }
    else{
        node* n = top;
        top = (top)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}
 
int main(){
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    
    linkedListTraversal(top);
 
    // int element = pop(top); 
    // printf("Popped element is %d\n", element);
    // linkedListTraversal(top);
    
    return 0;
}
