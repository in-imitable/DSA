#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node * next;
}node;

node* top = NULL;

void linkedListTraversal(node * ptr){
    while (ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int isEmpty(node *top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(node *top){
    node * p = new node;
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

node * push(node * top, int data){
    if(isFull(top)){
        cout<<"Stack Overflow!"<<endl;
    }
    else{
        node *n = new node;
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(node * top){
    if(isEmpty(top)){
        cout<<"Stack Underflow!"<<endl;
    }
    else{
        node * n = top;
        top = top->next;
        int x = n->data;
        delete(n);
        return x;
    }
}

int peek(int ind){
    node * ptr = top;
    for (int i = 0; (i<ind-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr!=NULL)
    {
        return ptr->data;
    }
    else{
        return -1;
    }
}

int main(){
    //Calling push() operation
    top = push(top, 12);
    top = push(top, 8);
    top = push(top, 25);
    top = push(top, 43);

    // linkedListTraversal(top);

    //Calling pop() operation
    // int element = pop(top); 
    // cout<<"Popped element is "<<element<<endl;
    // linkedListTraversal(top);

    //Performing peek() operation 
    linkedListTraversal(top);
    for (int i = 1; i <= 4; i++)
    {
        cout<<"Value at position "<<i<<" is: "<<peek(i)<<endl;
    }
    
    return 0;
}