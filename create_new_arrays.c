#include<stdio.h>
#include<stdlib.h>

typedef struct myArray
{
    int t_size;
    int u_size;
    int * ptr;
}myarr;

void crtArray(myarr *p, int tSize, int uSize){
    p->t_size = tSize;
    p->u_size = uSize;
    p->ptr = (int*)malloc(tSize*sizeof(int));
}

void setArray(myarr *p){
    int n;
    for (int i = 0; i < p->u_size; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &n);
        (p->ptr)[i] = n;
    }    
}
void showArray(myarr *p){
    for (int i = 0; i < p->u_size; i++)
    {
        printf("%d ", (p->ptr)[i]);
    }
    
}

int main(){
    myarr items;
    crtArray(&items, 50, 5);
    setArray(&items);
    showArray(&items);

    return 0;
}