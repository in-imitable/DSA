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

//Case 1: This function will insert at the first position of the linked list
node * insertAtFirst(node *head, int data){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

//Case 2: This function will insert in between of the linked list
node * insertAtIndex(node *head, int data, int index){
    node *ptr = (node*)malloc(sizeof(node));
    node *p = head;
    int i=0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

//Case 3: This function will insert at the last position of the linked list
node * insertAtEnd(node *head, int data){
    node * ptr = (node*)malloc(sizeof(node));
    node * p = head;
    ptr->data = data;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

//Case 4: This function will insert after the given node of the linked list
node * insertAfterNode(node *head, node* prevNode, int data){
    node * ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}


int main(){

    node *head; 
    node *second;
    node *third;
    node *fourth;

    //Allocate memory for node in the Lined List in Heap
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

    // head = insertAtFirst(head, 45);
    // linkListTraverse(head);
    
    // head = insertAtIndex(head, 45, 2);
    // linkListTraverse(head);
    
    // head = insertAtEnd(head, 45);
    // linkListTraverse(head);

    // head = insertAfterNode(head, second, 45);
    // linkListTraverse(head);
    
    return 0;
}