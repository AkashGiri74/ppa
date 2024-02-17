#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input(int *a,int n);//definition 
void show(int *a,int n,const char* msg);

void main ()
{

    int *a=NULL;
    int n;

    puts("enter number of elements to sort \n");
    scanf("%d",&n);
    if(n<0)
    {
        puts("invalid array input\n");
        exit(EXIT_FAILURE);
    }

    a=(int *)malloc(n*sizeof(int));
    if(a==NULL)
    {
        puts("error in memory alloction");
        exit(EXIT_FAILURE);
    }
    input(a,n);
    show(a,n,"before sort");
    free(a);
}
void input(int *a,int n)
{
    int i;
    srand(time(0));//current time//fuction to generate random number srand()
    for(i=0;i<n;i++)
    {
        a[i]=rand();
    }
}
void show(int *a,int n,const char * msg )
{
    int i;
    if(msg!=NULL)
    puts(msg);
    for(i=0;i<n;i++)
    {
        printf("a[%d] =%d\n",i,a[i]);
    }
}
