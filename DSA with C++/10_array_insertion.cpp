#include<iostream>
using namespace std;

void showData(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int insertData(int arr[], int size, int element, int index, int capacity){
    if(size>=capacity){
        return -1;
    }
    for (int i = size-1; i >= index ; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main(){
    
    int arr[50] = {21, 35, 2, 46, 35, 12, 5, 23};
    int size = 8, element = 25, index = 4, capacity = 50;
    showData(arr, size);

    insertData(arr, size, element, index, capacity);
    size+=1;
    cout<<"Array after insertion"<<endl;
    showData(arr, size);

    return 0;
}

