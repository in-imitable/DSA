//A program to generate random numbers and store/insert in an empty array

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void display(int arr[], int n);
void numInsert(int arr[], int size, int index, int num);

int main(){
    int arr[100];  
    // int size = sizeof(arr)/sizeof(int);

    int i, num; 
    srand(time(0)); 
    printf ("Program to get the random number from 1 to 100\n");  
    for (i = 0; i < 20; i++){  
        num = rand() % 20+1; // use rand() function to get the random number 
        printf("%d ", num);

        numInsert(arr, 20, i, num);
        
    }
    printf("\nElements of the arrays after insertion\n");
    display(arr, 20);
    
    return 0;
}

// Display function to print arrays
void display(int arr[], int n){
    //Code for Traversal
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insertion function
void numInsert(int arr[], int size, int index, int num){
    for(int i = size-1; i>=index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = num;
    // return 1;
}