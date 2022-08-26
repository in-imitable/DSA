#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node * next;
}node;

void linkedListTraverse(node * head){
    node * ptr = head;
    do{
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }while(ptr!=head);
    cout<<endl;
}

node * insertion(node * head, int data){
    node* ptr = new node;
    node * p = head;
    while(p->next!=head){
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main(){
    
    node * head = new node;
    node * second = new node;
    node * third = new node;
    node * fourth = new node;
    node * fifth = new node;

    head->data = 32;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 64;
    third->next = fourth;

    fourth->data = 26;
    fourth->next = fifth;

    fifth->data = 58;
    fifth->next = head;

    linkedListTraverse(head);

    head = insertion(head, 86);
    head = insertion(head, 73);
    head = insertion(head, 21);
    head = insertion(head, 44);
    linkedListTraverse(head);

    return 0;
}