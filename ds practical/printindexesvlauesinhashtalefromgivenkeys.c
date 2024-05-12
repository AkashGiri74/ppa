#include<stdio.h>
#include<stdlib.h>
int main ()
{   int arr[6]={10,15,13,21,99,34};
   int indexes[20]={-1};

    int size;
    printf("enter size of hash tabel");
    scanf("%d",&size);

    for(int i=0;i<6;i++)
    { 
        indexes[i]=(arr[i] % size);

    }
    printf("indexes of values in the hash tabel :");
    for(int i=0;i<size;i++)
    {
        printf("%d ",indexes[i]);
    }

}