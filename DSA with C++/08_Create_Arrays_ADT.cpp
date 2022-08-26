#include<iostream>
using namespace std;

typedef struct myArray
{
    int total_size;
    int used_size;
    int * ptr;
}myarr;

void createArray(myarr *p, int tSize, int uSize){
    p->total_size = tSize;
    p->used_size = uSize;
    p->ptr = new int(tSize);
}

void setData(myarr *p){
    int n;
    for (int i = 0; i < p->used_size; i++)
    {
        cout<<"Enter the element "<<i+1<<" ";
        cin>>n;
        (p->ptr)[i] = n;
    }  
}

void display(myarr *p){
    for (int i = 0; i < p->used_size; i++)
    {
        cout<<(p->ptr)[i]<<" ";
    }
    
}

int main(){

    myarr marks;
    createArray(&marks, 50, 10);

    setData(&marks);

    display(&marks);
    
    return 0;
}