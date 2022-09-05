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
    //Initializing Queue
    queue q;
    q.size = 400;
    q.front = q.rear = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    //BFS Implementation in Graph
    // int node;
    int i=5;
    int visited[7] = {0,0,0,0,0,0,0};
    int arr[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };

    printf("%d", i);
    visited[i] = 1;
    enqueue(&q, i); //Enqueue i for exploration
    while(!isEmpty(&q)){
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(arr[node][j]==1 && visited[j]==0){
                printf("%d", j);
                visited[j]=1;
                enqueue(&q, j);
            }
        }
    
    }
    
    return 0;
}