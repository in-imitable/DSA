#include<stdio.h>

void display(int * arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Merge(int A[], int low, int mid, int high){
    int i, j, k, B[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        B[k] = A[i];
        i++;
        k++;
    }
    while(j<=high){
        B[k] = A[j];
        j++;
        k++;
    }
    for(i=low; i<= high; i++){
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
}

int main(){
    
    int arr[] = {21, 65, 68, 74, 24, 15, 62, 23, 88, 26, 21, 65, 68, 74, 24, 15, 62, 23, 88, 26};
    int n = 20;

    display(arr, n);
    
    mergeSort(arr, 0, n-1);
    
    display(arr, n);

    return 0;
}