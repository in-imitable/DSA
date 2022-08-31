#include<iostream>
using namespace std;

void display(int * arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertionSort(int* arr, int n){
    int key, j;
    for(int i=1; i<=n-1; i++){
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key; 
    }  
}


int main(){

    int arr[] = {21, 65, 68, 74, 24, 15, 62, 23, 88, 26};
    int n = 10;

    display(arr, n);
    
    insertionSort(arr, n);
    
    display(arr, n);
    
    return 0;
}