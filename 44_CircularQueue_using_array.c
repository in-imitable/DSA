#include<stdio.h>
#include<stdlib.h> 

typedef struct CircularQueue{
    int size, front, rear;
    int * arr;
}queue;

int isEmpty(queue* q){
    if(q->rear==q->front){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(queue* q){
    if((q->rear+1)%q->size==q->front){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(queue * q, int val){
    if(isFull(q)){
        printf("The Queue is OverFlow!\n");
    }
    else{
        printf("Enqued element: %d\n", val);
        q->rear = (q->rear+1)%q->size;
        q->arr[q->rear] = val;
    }
}

int dequeue(queue * q){
    int val = -1;
    if(isEmpty(q)){
        printf("The Queue is UnderFlow!\n");
    }
    else{
        q->front = (q->front+1)%q->size;
        val = q->arr[q->front];
    }
    return val;
}

int main(){

    queue q;
    q.size = 5;
    q.front = q.rear = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 25);
    enqueue(&q, 32);
    enqueue(&q, 41);

    printf("Dequed element: %d\n", dequeue(&q));

    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }

    return 0;
}