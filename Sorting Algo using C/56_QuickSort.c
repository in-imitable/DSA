#include<stdio.h>

void display(int * arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//Partition method
int partition(int* arr, int low, int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;

    do{
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }while(i<j);

    swap(&arr[low], &arr[j]);
    return j;
}

// QuickSort method
void quickSort(int* arr, int low, int high){
    int partitionIndex; //Index of pivot after partition

    if(low<high){
        partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex-1);  //Sort left sub-arrray
        quickSort(arr, partitionIndex+1, high); //Sort right sub-array
    }
}

int main(){
    
    int arr[] = {21, 65, 68, 74, 24, 15, 62, 23, 88, 26};
    int n = 10;

    display(arr, n);
    
    quickSort(arr, 0, n-1);
    
    display(arr, n);

    return 0;
}