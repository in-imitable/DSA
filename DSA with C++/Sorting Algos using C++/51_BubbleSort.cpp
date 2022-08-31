#include<iostream>
using namespace std;

void display(int * arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// void swap(int *a, int *b){
//     int tmp = *a;
//     *a = *b;
//     *b = tmp;
// }

void bubbleSort(int * arr, int n){
    for (int i = 0; i < n-1; i++)   //For number of passes
    {   
        cout<<"Working on pass number "<<i+1<<endl;
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
        cout<<"Working on pass number "<<i+1<<endl;
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
    int n = 10;

    display(arr, n);
    // cout<<"Number of passes is higher"<<endl;
    // bubbleSort(arr, n);
    
    cout<<"Number of passes is lesser and better performace"<<endl;
    bubbleSortAdaptive(arr, n);
    
    display(arr, n);

    return 0;
}