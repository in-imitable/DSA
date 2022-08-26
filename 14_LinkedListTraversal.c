#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}node;

void linkListTraverse(node * ptr){
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main(){

    node *head; 
    node *second;
    node *third;
    node *fourth;

    //Allocate memory for node in the Linked List in Heap
    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));

    //Link every nodes
    head->data = 7;
    head->next = second;
    
    second->data = 9;
    second->next = third;

    third->data = 10;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = NULL;

    linkListTraverse(head);
    
    return 0;
}