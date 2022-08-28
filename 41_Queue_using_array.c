#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int size, front, rear;
    int * arr;
}queue;

void queueTraverse(queue* q){
    for(int i=q->front+1; i<=q->rear; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int isFull(queue* q){
    if(q->rear==q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(queue* q){
    if(q->rear==q->front){
        return 1;
    }
    return 0;
}

void enqueue(queue* q, int val){
    if(isFull(q)){
        printf("Queue is full!");
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int dequeue(queue* q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue is empty!");
    }
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int main(){

    queue q;
    q.size = 100;
    q.front = q.rear = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    //Enqueue few elements in the queue
    enqueue(&q, 31);
    enqueue(&q, 14);
    enqueue(&q, 65);
    enqueue(&q, 42);
    enqueue(&q, 78);
    enqueue(&q, 11);
    enqueue(&q, 26);

    queueTraverse(&q);

    printf("Dequeue element is %d\n", dequeue(&q));
    printf("Dequeue element is %d\n", dequeue(&q));
    printf("Dequeue element is %d\n", dequeue(&q));

    queueTraverse(&q);

    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    
    return 0;
}