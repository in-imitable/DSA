#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int stackTop(stack* sp){
    return sp->arr[sp->top];
}

int precedence(char ch){
    if(ch=='*' || ch=='/')
        return 3;
    if(ch=='+' || ch=='-')
        return 2;
    else
        return 0;
}

int isOperator(char ch){
    if(ch=='*' || ch=='/' || ch=='+' || ch=='-')
        return 1;
    else
        return 0;
}

char * infixToPostfix(char * infix){
    stack * s = (stack*) malloc(sizeof(stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char*) malloc(s->size*sizeof(char));
    char * postfix = (char*) malloc((strlen(infix)+1)*sizeof(char));
    int i=0, j=0;
    while (infix[i]!='\0')
    {
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i]) > precedence(stackTop(s))){
                push(s, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while (!isEmpty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;    
}


int main(){

    char * infix = "a-b+c*d-p/q";

    printf("The postfix is %s", infixToPostfix(infix));



    return 0;
}