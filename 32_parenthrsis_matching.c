#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int size;
    int top;
    char *arr;
} stack;

int isEmpty(stack *ptr){
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack * ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

//Pop funtion to pop the elements from the stack
int pop(stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop to the stack\n");
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char parenthesisMatch(char * exp){
    //Create and initialize the stack
    stack * s;
    s->size = 100;
    s->top = -1;
    s->arr = (char *) malloc(s->size*sizeof(char));

    for(int i=0; exp[i]!='\0'; i++){
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

    char * exp = "(8-7)+(6*5)-(6/2)";

    //Check if stack is empty
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }

    return 0;
}