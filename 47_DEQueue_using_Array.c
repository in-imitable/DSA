#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int size, front, rear;
    int * arr;
}queue;

void queueTraverse(queue* q){
    printf("Queue elements:\n" );
    for(int i=0; i<=q->rear; i++){
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

void enqueueR(queue* q, int val){
    if(isFull(q)){
        printf("Queue is full!\n");
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
    }
}

int dequeueF(queue* q){
    int a;
    if(isEmpty(q)){
        printf("Queue is empty!\n");
    }
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

void enqueueF(queue * q, int val){
    if(isFull(q) || q->front==-1){
        printf("Queue is full!\n");
    }
    else{
        q->arr[q->front] = val;
        q->front--;
    }
}

int dequeueR(queue * q){
    int val;
    if(isEmpty(q)){
        printf("Queue is empty!\n");
    }
    else{
        val = q->arr[q->rear];
        q->rear--;
        return val;
    }
}

int main(){

    queue * q = (queue *)malloc(sizeof(queue));
    q->size = 10;
    q->front = q->rear = -1;
    q->arr = (int*)malloc(q->size*sizeof(int));

    //Insert elements from rear in the queue using enqueue() method
    enqueueR(q, 31);
    enqueueR(q, 14);
    enqueueR(q, 65);
    enqueueR(q, 42);
    enqueueR(q, 78);
    enqueueR(q, 11);
    enqueueR(q, 26);
    queueTraverse(q);



    //Delete elements from front in the queue using dequeue() method
    printf("Dequeue element is %d\n", dequeueF(q));
    printf("Dequeue element is %d\n", dequeueF(q));
    printf("Dequeue element is %d\n", dequeueF(q));

    enqueueF(q, 87);
    enqueueF(q, 35);
    enqueueF(q, 32);
    queueTraverse(q);

    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    
    return 0;
}