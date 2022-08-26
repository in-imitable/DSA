#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){

    FILE *ptr=NULL;
    char name[20];
    long phn;
    int age;
    ptr = fopen("myfile.txt", "w");

    printf("Enter your name: ");
    gets(name);
    fprintf(ptr, "Name: %s", name);

    printf("Enter your phone no: ");
    scanf("%ld", &phn);
    fprintf(ptr, "\nPhone no: %ld", phn);

    printf("Enter your age: ");
    scanf("%d", &age);
    fprintf(ptr, "\nYour age: %d", age);

    printf("Done");

    fclose(ptr); 
    return 0;
}