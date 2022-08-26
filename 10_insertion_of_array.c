#include<stdio.h>
#include<stdlib.h>

void display(int arr[], int n){
    //Code for Traversal
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsert(int arr[], int size, int element, int capacity, int index){
    //Code for Insertion
    if(size>=capacity){
        return -1;
    }
    for(int i = size-1; i>=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main(){
    
    int arr[100] = {34,45,54,12,67,12,45};
    int size = 7, element = 23, index = 6;
    display(arr, size);
    
    indInsert(arr, size, element, 100, index);
    size+=1;
    display(arr, size);
    // int result = indInsert(arr, size, element, 100, index);
    // size+=1;
    // //Check whether insertion is successful or not.
    // if(result==1){
    //     printf("Insertion successful\n");
    //     display(arr, size); 
    // }
    // else printf("Insertion failed!!!\n");

    return 0;
}