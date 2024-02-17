#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void input(int *a,int n);//definition 
void show(int *a,int n,const char* msg);
void bubble_sort(int *a,int n);
void swap(int *n1,int* n2);
void main ()
{

    int a[]=NULL;
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
    bubble_sort(a,n);
    show(a,n,"after sort");
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
void bubble_sort(int *a,int n)
{
    int temp,i ,itr;  
    for(itr=1;itr<n;itr++)
    for(i=0;i<n-itr;i++)//  for(i=0;i<n;i++)//i=0 
                                     //i=1
                                      //12 34 45 23 10 24
                                      //i=2
    { 
        if(a[i]>a[i+1])
       {
         swap(&a[i],&a[i+1]);
        }
      

    }

}
void swap(int *n1,int *n2)
{
    int  temp;
    
        temp=*n1;
        *n1=*n2;
        *n2=temp;
    
}
// 12  45   34  23  10  24 