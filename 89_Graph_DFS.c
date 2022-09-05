#include<stdio.h>

//Initializing Graph
int visited[7] = {0,0,0,0,0,0,0};
int arr[7][7] = {
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0},
};

void DFS(int i){
    printf("%d ", i);
    visited[i] = 1;
    for(int j=0; j<7; j++){
        if(arr[i][j]==1 && visited[j]==0){
            DFS(j);
        }
    }
}

int main(){

    //Calling DFS() function
    DFS(5);
    
    return 0;
}