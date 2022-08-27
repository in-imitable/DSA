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

int match(char a, char b){
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
    if(a=='{' && b=='}'){
        return 1;
    }
    return 0;
}

char parenthesisMatch(char * exp){
    //Create and initialize the stack
    stack * s;
    s->size = 100;
    s->top = -1;
    s->arr = (char *) malloc(s->size*sizeof(char));
    char popped_ch;

    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(s, exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty(s)){
                return 0;
            }
            popped_ch = pop(s);
            if(!match(popped_ch, exp[i])){
                return 0;
            }
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

    char * exp = "{(8-7)+[(6*5)-(6/2)]}";

    if(parenthesisMatch(exp)){
        printf("The parenthesis is balanced");
    }
    else{
        printf("The parenthesis is not balanced");
    }

    return 0;
}