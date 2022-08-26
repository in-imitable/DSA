#include<stdio.h>
#include<stdlib.h>

typedef struct myArray{
    int total_size;
    int used_size;
    int *ptr;
}marr;

void createArray(marr *a, int tSize, int uSize){
    a->total_size=tSize;
    a->used_size=uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void setData(marr *a){
    int n;
    for (int i = 0; i < a->used_size; i++){
        printf("Enter the element %d: ", i+1);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    } 
}

void showData(marr *a){
    for (int i = 0; i < a->used_size; i++){
        printf("%d\n", (a->ptr)[i]);
    } 
}

int main(){

    marr marks;
    createArray(&marks, 50, 10);
    setData(&marks);
    showData(&marks);
    
    return 0;
}