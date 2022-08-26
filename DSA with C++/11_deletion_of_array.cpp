#include<iostream>
using namespace std;

void display(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void indexDelete(int arr[], int size, int index){
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
}

int main(){
    int arr[100] = {12, 13, 65, 54, 48, 75, 15, 26};
    int size=8, index = 3;

    display(arr, size);
    indexDelete(arr, size, index);
    size -= 1;
    display(arr, size);
    
    return 0;
}