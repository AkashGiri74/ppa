//sort array only even no and place it at odd  no position
#include<stdio.h>
void main ()
{  
    int i,j, n,a[10],temp;
	printf("enter how many elements \n");
	scanf("%d",&n);
	printf("enter elemnts in array\n");
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);

	for(i=0;i<n;i++)
     	{
     	  for(j=i+1;j<n;j++)
            {  
               if(a[j]%2==0 && a[i]%2==0)
                 {
                     if(a[i]>a[j])
	              { 
	                temp=a[i];
		       a[i]=a[j];
	                a[j]=temp;
		      }
	        }
	    }
         }   

	printf("elements after sort\n");
	   for(i=0;i<n;i++)
	   printf("%d\n",a[i]);

}