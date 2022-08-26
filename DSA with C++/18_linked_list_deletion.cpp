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

//Case 1: Deleting the first element from the linked list
node * deleteFirst(node *head){
    node *p = head;
    head = p->next;
    delete(p);
    return head;
}

//Case 2: Deleting the element at a given index from the linked list
node * deleteAtIndex(node *head, int index){
    node *p = head;
    node *q = head->next;
    for(int i=0; i<index-1; i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    delete(q);
    return head;
}

//Case 3: Deleting the last element
node * deleteAtLast(node *head){
    node *p = head;
    node *q = head->next;
    while (q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    delete(q);
    return head;
}

//Case 4: Deleting the element with a given value from the linked list
node * deleteByValue(node *head, int value){
    node *p = head;
    node *q = head->next;
    while (q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next; 
    }
    if(q->data==value){
        p->next = q->next;
        delete(q);
    }
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

    // head = deleteFirst(head);
    // linkListTraverse(head);

    // head = deleteAtIndex(head, 2);
    // linkListTraverse(head);

    // head = deleteAtLast(head);
    // linkListTraverse(head);
    
    head = deleteByValue(head, 43);
    linkListTraverse(head);

    return 0;
}