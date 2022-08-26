#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int size;
    int top;
    int *arr;
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

int main(){

    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Check if stack is empty
    if(isEmpty(s)){
        printf("The stack is empty\n");
    } 
    else{
        printf("The stack is not empty\n");
    }

    // Check if stack is full
    if(isFull(s)){
        printf("The stack is full\n");
    } 
    else{
        printf("The stack is not full\n");
    }

    return 0;
}