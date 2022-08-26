#include<iostream>
using namespace std;

void display(int arr[], int size){
    for (int i = 0; i < size-1; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Linear search function
int linearSearch(int arr[], int size, int element){
    for(int i = 0; i < size; i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}

//Binary search function
int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;

    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(arr[mid]<element){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}

int main(){

    // //Unsorted array for linear search
    // int arr[]={21, 65, 2, 45, 57, 58, 5, 68, 6, 28, 57};
    // int size = sizeof(arr)/sizeof(int);
    // int element = 5;
    // display(arr, size);
    // int searched = linearSearch(arr, size, element);
    // cout<<"The element found at index "<<searched;

    //Sorted array for binary search
    int arr[] = {3,5,6,7,8,12,15,19,26,27,33,35};
    int size = sizeof(arr)/sizeof(int);
    int element = 15;
    display(arr,size);
    int searched = binarySearch(arr, size, element);
    cout<<"The element found at index "<<searched;

    return 0;
}