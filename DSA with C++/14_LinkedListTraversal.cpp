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

    return 0;
}