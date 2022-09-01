#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void display(int * arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maximum(int * arr, int n){
    int max = INT_MIN;
    for(int i=0; i<n; i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int* arr, int n){
    int i, j;
    int max = maximum(arr, n);
    int* count = (int*)malloc((max+1)*sizeof(int));

    //Initializing count array with zero
    for(i = 0; i<=max; i++){
        count[i] = 0;
    }

    //Traversing all the elements in the given array
    for(i=0; i<n; i++){
        count[arr[i]] += 1;
    }

    i = 0;  //Counter for count array
    j = 0;  //Counter for given array
    while(i<=max){
        if(count[i]>0){
            arr[j] = i;
            count[i] -= 1;
            j++;
        }
        else{
            i++;
        }
    }
}

int main(){
    
    int arr[] = {21, 65, 68, 74, 24, 15, 62, 23, 88, 26};
    int n = 10;

    display(arr, n);

    countSort(arr, n);
    
    display(arr, n);

    return 0;
}