#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
}node;

void linkedListTraverse(node * head){
    node * ptr = head;
    while(ptr->next!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<ptr->data<<" ";
    cout<<endl;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->prev;
    }
}

int main(){

    node * head = new node;
    node * second = new node;
    node * third = new node;
    node * fouth = new node;
    node * fifth = new node;
    node * sixth = new node;

    head->data = 11;
    head->next = second;
    head->prev = NULL;

    second->data = 22;
    second->next = third;
    second->prev = head;

    third->data = 33;
    third->next = fouth;
    third->prev = second;

    fouth->data = 44;
    fouth->next = fifth;
    fouth->prev = third;

    fifth->data = 55;
    fifth->next = sixth;
    fifth->prev = fouth;

    sixth->data = 66;
    sixth->next = NULL;
    sixth->prev = fifth;

    linkedListTraverse(head);

    return 0;
}