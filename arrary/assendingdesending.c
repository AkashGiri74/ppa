#include<stdio.h>
void main()
{
  int n,a[10],temp=0;
printf("enter how many elements");
scanf("%d",&n);
printf("enter elements\n");
for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
printf("elemnts are\n");
   for(int i=0;i<n/2;i++)
      {   for(int j=i+1;j<n/2;j++)
		  { 
	       if (a[i] <a[j])
			  { temp=a[i];
		          a[i]=a[j];
				  a[j]=temp;
	            }
	       }
	  }
	  for(int i=n/2;i<n;i++)
      {   for(int j=i+1;j<n;j++)
		  { 
	       if (a[i] >a[j])
			  { temp=a[i];
		          a[i]=a[j];
				  a[j]=temp;
	            }
	       }
	  }
	printf("sorted array is \n");
	     for( int i=0;i<n;i++)
		 printf("%d\t",a[i]);
		 }
