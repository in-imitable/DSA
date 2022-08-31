#include<stdio.h>

void display(int * arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int * arr, int n){
    for (int i = 0; i < n-1; i++)   //For number of passes
    {   
        printf("Working on pass number %d\n", i+1);
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

//Modifying bubbleSort to make it adaptive to better performance
void bubbleSortAdaptive(int * arr, int n){
    int isSorted = 0;
    for (int i = 0; i < n-1; i++)   //For number of passes
    {   
        printf("Working on pass number %d\n", i+1);
        isSorted = 1;
        for (int j = 0; j < n-1-i; j++) //For comparison of each passes
        {
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                isSorted = 0;
            }
        } 
        if(isSorted){
            return;
        }
    }    
}

int main(){
    
    int arr[] = {21, 65, 68, 74, 24, 15, 62, 23, 88, 26};
    // int arr[] = {21, 25, 29, 35, 37, 42, 52, 56, 75, 85};
    int n = 10;

    display(arr, n);

    // printf("Number of passes is higher\n");
    // bubbleSort(arr, n);
    
    printf("Number of passes is lesser and better performace\n");
    bubbleSortAdaptive(arr, n);
    
    display(arr, n);

    return 0;
}