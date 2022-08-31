#include<stdio.h>

void display(int * arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// void swap(int a, int b){
//     int temp = a;
//     a = b;
//     b = temp;
// }

void bubbleSort(int * arr, int n){
    for (int i = 0; i < n-1; i++)   //For number of passes
    {
        for (int j = 0; j < n-1-i; j++) //For comparison of each passes
        {
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }  
    }    
}

int main(){
    
    int arr[] = {21, 65, 68, 74, 24, 15, 62, 23, 88, 26};
    int n = 10;

    display(arr, n);
    bubbleSort(arr, n);
    display(arr, n);

    return 0;
}