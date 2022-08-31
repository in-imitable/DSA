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

void selectionSort(int* arr, int n){
    int indexMin;
    for(int i=0; i<n-1; i++){
        indexMin = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[indexMin]){
                indexMin = j;
            }
        }
        swap(&arr[i], &arr[indexMin]);
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