#include<iostream>
using namespace std;

typedef struct Stack{
    int size;
    int top;
    int * arr;
}stack;

int isEmpty(stack * p){
    if(p->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(stack * p){
    if(p->top == p->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int push(stack * p, int val){
    if(isFull(p)){
        cout<<"Stack Overflow! Cannot push more value"<<endl;
    }
    else{
        p->top++;
        p->arr[p->top] = val;
    }
}

int pop(stack * p){
    if(isEmpty(p)){
        cout<<"Stack Underflow! Cannot pop more values"<<endl;    
    }
    else{
        int val = p->arr[p->top];
        p->top--;
        return val;
    }
}

int peek(stack* p, int i){
    int arrIndex = p->top-i+1;
    if(arrIndex<0){
        cout<<"Invalid Position"<<endl;
    }
    else{
        return p->arr[arrIndex];
    }
}

int stackTop(stack * p){
    return p->arr[p->top];
}

int stackBottom(stack * p){
    return p->arr[0];
}

int main(){

    stack *s = new stack;
    s->size = 10;
    s->top = -1;
    s->arr = new int;
    // s->arr = new int[s->size];

    cout<<"Stack has been created successfully!"<<endl;

    cout<<"Before pushing: Empty "<<isEmpty(s)<<endl;
    cout<<"Before pushing: Full "<<isFull(s)<<endl;

    //Calling push() funtion to insert elements in the Stack
    push(s, 21);
    push(s, 16);
    push(s, 33);
    push(s, 45);
    push(s, 23);
    push(s, 78);
    push(s, 99);
    push(s, 11);
    push(s, 56);
    push(s, 82);

    cout<<"After pushing: Empty "<<isEmpty(s)<<endl;
    cout<<"After pushing: Full "<<isFull(s)<<endl;

    //Calling pop() funtion to delete elements from the Stack
    // cout<<"Popped "<<pop(s)<<" from the stack"<<endl;
    // cout<<"Popped "<<pop(s)<<" from the stack"<<endl;
    // cout<<"Popped "<<pop(s)<<" from the stack"<<endl;

    //Printing values from top of the stack using peek() function
    for(int j = 1; j<=s->top+1; j++){
        cout<<"The value at position "<<j<<": "<<peek(s, j)<<endl;
    }

    cout<<"The top most value of the stack is "<<stackTop(s)<<endl;
    cout<<"The bottom most value of the stack is "<<stackBottom(s)<<endl;
    
    return 0;
}