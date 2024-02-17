#include<stdio.h>
void main () 
{ 
int n,i;
int arr[100];
     printf("enter how many elements\n");
     scanf("%d",&n);
     printf("enter elements in array\n");
       for (i=0;i<n;i++) 
	   {    
   scanf("%d",&arr[i]);
	   }
 int max=arr[0];
        for (i=0;i<n;i++) 
        { if ( max<arr[i]) 
            max =arr[i];
           }
           printf("maximum element is%d",max);
      }