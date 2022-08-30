#include<stdio.h>
#include<stdlib.h>

struct Node *front = NULL;
struct Node *rear = NULL;

typedef struct Node{
    int data;
    struct Node* next;
}node;

void linkedListTraverse(node* ptr){
    printf("The elements of this linked list\n");
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(int val){
    node * n = (node*)malloc(sizeof(node));
    if(n==NULL){
        printf("The Queue is full");
    }
    else{
        n->data = val;
        n->next = NULL;
        if (front==NULL)    //Condition check for Queue is Full
        {
            front=rear=n;
        }
        else{
            rear->next = n;
            rear = n;
        }        
    }
}

int dequeue(){
    int val = -1;
    node * ptr = front;
    if(front==NULL){    //Condition check for Queue is Empty
        printf("The Queue is empty");
    }
    else{
        front = front->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main(){

    // linkedListTraverse(front);

    enqueue(34);
    enqueue(25);
    enqueue(16);
    enqueue(64);
    enqueue(58);
    
    linkedListTraverse(front);
    printf("Dequed element: %d\n", dequeue());
    printf("Dequed element: %d\n", dequeue());
    printf("Dequed element: %d\n", dequeue());
    linkedListTraverse(front);

    return 0;
}