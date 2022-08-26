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

int main(){

    stack *s = new stack;
    s->size = 50;
    s->top = -1;
    s->arr = new int[s->size];

    if(isEmpty(s)){
        cout<<"Empty Stack"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;
    }

    if(isFull(s)){
        cout<<"Full Stack"<<endl;
    }
    else{
        cout<<"Not Full"<<endl;
    }
    
    return 0;
}