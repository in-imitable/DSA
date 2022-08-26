#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
}stack;

int isEmpty(stack *s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

//Push funtion to push the elements from the stack
void push(stack * ptr, int val){
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
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// Peek funtion to get position of the elements from the top in stack
int peek(stack * ptr, int i){
    int arrayInd = ptr->top-i+1;
    if(arrayInd<0){
        printf("Invalid position\n");
        return -1;
    }
    else{
        return ptr->arr[arrayInd];
    }
}

int stackTop(stack * ptr){
    int top = ptr->arr[ptr->top];
    return top;
}

int stackBottom(stack * ptr){
    int bottom = ptr->arr[0];
    return bottom;
}

int main(){

    stack *s = (stack *)malloc(sizeof(stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size*sizeof(int));

    printf("Stack has been created successfully\n");
    
    printf("Before pushing, Full: %d\n", isFull(s));
    printf("Before pushing, Empty: %d\n", isEmpty(s));

    //Push elements using push() funstion
    push(s, 7);
    push(s, 5);
    push(s, 11);
    push(s, 9);
    push(s, 13);
    push(s, 4);
    push(s, 16);
    push(s, 19);
    push(s, 8);
    push(s, 15);

    printf("After pushing, Full: %d\n", isFull(s));
    printf("After pushing, Empty: %d\n", isEmpty(s));

    //Pop the elements using pop() funtion
    // printf("Popped %d from the stack\n", pop(s));
    // printf("Popped %d from the stack\n", pop(s));
    // printf("Popped %d from the stack\n", pop(s));
    // printf("Popped %d from the stack\n", pop(s));
    // printf("Popped %d from the stack\n", pop(s));

    //Printing values from the stack using peek()
    for (int j = 1; j <= s->top+1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(s, j));
    }

    printf("The top most value of this stack is %d\n", stackTop(s));
    printf("The bottom most value of this stack is %d\n", stackBottom(s));
    

    return 0;
}