#include<stdio.h>
#include<stdlib.h>
void main ()
{
    int a[4]={11,12,14,16};
    int index[4];
    
    int size,i;

     printf("enter size of hash arrary :");
     scanf("%d",&size);

     for(i=0;i<4;i++)
     {

        index[i]=(a[i] % size);
     }

     printf("indexes of the array :");
     for(i=0;i<4;i++)
     {
        printf("%d ",index[i]);
     }

}