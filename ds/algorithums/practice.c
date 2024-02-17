#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void input(int*,int );
void show(int*,int ,const char* msg);
void main ()
{
    int *a=NULL;
    int n;
    printf("enter how many elements:");
    scanf("%d",&n);

    if (n<0)
    {
        puts("invalid input\n");
        exit(EXIT_FAILURE);
    }
    a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    { puts("errror in memoery sllocation\n");
       exit(EXIT_FAILURE);
    }
    input(a,n);
    show(a,n,"before sort\n");
    free(a);
}
void input(int *a,int n)
{  int i;
  srand(time(0));
   
   for(i=0;i<n;i++)
   {
    a[i]=rand();
   }

}
void show(int*a,int n ,const char* msg)
{  int i;
   if (msg==NULL)
   puts( msg);
   for(i=0;i<n;i++)
   {
    printf("a[%d]=%d\n",i,a[i]);
   }

}