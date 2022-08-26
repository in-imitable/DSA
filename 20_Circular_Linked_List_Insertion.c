#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}node;

void linkListTraverse(node * head){
    node * ptr = head;
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
    printf("\n");
}


node * insertAtFirst(node * head, int data){
    node * ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    node * p = head->next;

    while(p->next!=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main(){

    node *head; 
    node *second;
    node *third;
    node *fourth;
    node *fifth;

    //Allocate memory for node in the Lined List in Heap
    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
    fifth = (node *)malloc(sizeof(node));

    //Link every nodes
    head->data = 7;
    head->next = second;
    
    second->data = 9;
    second->next = third;

    third->data = 10;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = fifth;

    fifth->data = 15;
    fifth->next = head;

    linkListTraverse(head);

    head = insertAtFirst(head, 18);
    head = insertAtFirst(head, 21);
    head = insertAtFirst(head, 23);
    linkListTraverse(head);
    
    return 0;
}