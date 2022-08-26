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
    printf("\n");
}

//Case 1: Deleting the first element from the linked list
node * deleteFirst(node * head){
    node * p = head;
    head = p->next;
    free(p);
    return head;
}

//Case 2: Deleting the element at a given index from the linked list
node * deleteAtIndex(node * head, int index){
    node * p = head;
    node * q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;    
}

//Case 3: Deleting the last element
node * deleteAtLast(node * head){
    node * p = head;
    node * q = head->next;
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

//Case 4: Deleting the element with a given value from the linked list
node * deleteByValue(node * head, int value){
    node * p = head;
    node * q = head->next;
    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if (q->data==value){
        p->next = q->next;
        free(q);
    }
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

    fourth->data = 15;
    fourth->next = fifth;

    fifth->data = 11;
    fifth->next = NULL;

    linkListTraverse(head);

    // head = deleteFirst(head);
    // linkListTraverse(head);

    // head = deleteAtIndex(head, 2);
    // linkListTraverse(head);

    // head = deleteAtLast(head);
    // linkListTraverse(head);
    
    head = deleteByValue(head, 9);
    linkListTraverse(head);
    
    return 0;
}