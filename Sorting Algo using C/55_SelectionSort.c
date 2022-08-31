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

// Selection sort method
void selectionSort(int* arr, int n){
    int indMin, tmp;
    for (int i = 0; i < n-1; i++){
        indMin = i;
        for (int j = i+1; j < n; j++){
            if(arr[j] < arr[indMin]){
                indMin = j;
            }
        }
        swap(&arr[i], &arr[indMin]);
    }
    
}

int main(){
    
    int arr[] = {21, 65, 68, 74, 24, 15, 62, 23, 88, 26};
    int n = 10;

    display(arr, n);
    
    selectionSort(arr, n);
    
    display(arr, n);

    return 0;
}