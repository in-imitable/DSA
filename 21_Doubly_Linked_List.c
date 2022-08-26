#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
}node;

void linkedlistTraversal(node * head){
    node * p = head;
    while(p->next!=NULL){
        printf ("%d ", p->data);
        p = p->next;
    }
    // printf("\n");
    // printf ("%d ", p->data);
    while(p!=NULL){
        printf ("%d ", p->data);
        p = p->prev;
    }

}

int main(){

    node * head = (node*)malloc(sizeof(node));
    node * second = (node*)malloc(sizeof(node));
    node * third = (node*)malloc(sizeof(node));
    node * fourth = (node*)malloc(sizeof(node));
    node * fifth = (node*)malloc(sizeof(node));
    node * sixth = (node*)malloc(sizeof(node));

    head->data = 15;
    head->next = second;
    head->prev = NULL;

    second->data = 23;
    second->next = third;
    second->prev = head;

    third->data = 27;
    third->next = fourth;
    third->prev = second;

    fourth->data = 31;
    fourth->next = fifth;
    fourth->prev = third;

    fifth->data = 22;
    fifth->next = sixth;
    fifth->prev = fourth;

    sixth->data = 46;
    sixth->next = NULL;
    sixth->prev = fifth;
    
    linkedlistTraversal(head);

    return 0;
}