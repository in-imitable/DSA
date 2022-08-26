#include<iostream>
#include<cstring>
using namespace std;

typedef struct Stack{
    int size;
    int top;
    char * arr;
}stack;

int isEmpty(stack * s){
    if(s->top==-1){
        return 1;
    }
    else{ 
        return 0;
    }
}

int isFull(stack * s){
    if(s->top==s->size-1){
        return 1;
    }
    else{ 
        return 0;
    }
}

void push(stack * ptr, int val){
    if(isFull(ptr)){
        cout<<"Stack Overflow! Cannot push more values"<<endl;
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(stack * ptr){
    if(isFull(ptr)){
        cout<<"Stack Underflow! Cannot pop more values"<<endl;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char parenthesesMatch(char* exp){
    //Create and initialize the stack
    stack* s;
    s->size = 100;
    s->top = -1;
    s->arr = new char(s->size);

    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(s, '(');
        }
        else if(exp[i]==')'){
            if(isEmpty(s)){
                return 0;
            }
            pop(s);
        }
    }
    if(isEmpty(s)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    char * exp = "(8-5)*2-((4/2)+9)";

    if(parenthesesMatch(exp)){
        cout<<"The parentheses is matching";
    }
    else{
        cout<<"The parentheses is not matching";
    }
    
    return 0;
}