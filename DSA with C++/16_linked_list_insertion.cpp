#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node * next;
}node;

void linkListTraverse(node * p){
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

//Case 1: This function will insert at the first position of the linked list
node * insertAtFirst(node *head, int data){
    node * ptr = new node;
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

//Case 2: This function will insert in between of the linked list
node * insertAtIndex(node *head, int data, int index){
    node *ptr = new node;
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
    node *ptr = new node;
    node *p = head;
    ptr->data = data;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

//Case 4: This function will insert after the given node of the linked list
node * insertAfterNode(node *head, int data, node *prevNode){
    node *ptr = new node;
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main(){
    //Declaring variables of node type and allocate memory in heap 
    node *head = new node;
    node *second = new node;
    node *third = new node;
    node *fouth = new node;
    node *fifth = new node;

    //link every nodes
    head->data = 21;
    head->next = second;

    second->data = 14;
    second->next = third;

    third->data = 36;
    third->next = fouth;

    fouth->data = 43;
    fouth->next = fifth;

    fifth->data = 48;
    fifth->next = NULL;

    linkListTraverse(head);

    // head = insertAtFirst(head, 11);
    // linkListTraverse(head);
    
    // head = insertAtIndex(head, 11, 3);
    // linkListTraverse(head);

    // head = insertAtEnd(head, 11);
    // linkListTraverse(head);

    head = insertAfterNode(head, 11, third);
    linkListTraverse(head);


    return 0;
}