#include<stdio.h>

void display(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void indDelete(int arr[], int size, int index){
    for(int i=index; i<size-1; i++){
        arr[i]=arr[i+1];
    }
}

int main(){
    
    int arr[100] = {12, 35, 11, 5, 23, 2};
    int size = 6, index = 2;

    display(arr, size);
    indDelete(arr, size, index);
    size-=1;
    display(arr, size);

    return 0;
}