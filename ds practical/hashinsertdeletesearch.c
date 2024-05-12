#include<stdio.h>
#include<stdlib.h>
#define size 7
int arr[size];
int init ()
{
    for(int i=0;i<size;i++)
        arr[i]=-1;
          
}
int insert(int value)
{
    int key=value %size;
    
    if(arr[key]==-1)
    {
        arr[key]=value;
        printf("\n%d is inserted at %d\n",value,key);
    }
    else
    {
        printf("collision occur  arr[%d] has already have element %d\n ",key,arr[value]);
        printf("unable to insert elemet %d\n",value);

    }

}
int delete(int value)
{
   int  key=value% size;
     arr[key]=-1;
     printf("element is deleted\n");
}
int print()
{   int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
int search(int value)
{   int key;
    key=value %size;
    if(arr[key]==value)
    {
    printf("%d found at index %d ",value,key);
    }
    else{
        printf("%d not found ",value);
    }
}
int main ()
{
    init();
    insert(10);//10% 7==3
    insert(7);// 7% 7==0
    insert(8);//3%7==2
    insert(20);//
    printf("elements are:");
     print();
      int value; 
     printf("\nenter element to search :");
     scanf("%d",&value);
     search(value);

    printf("\ndeleting element 10..\n");
    delete(10);
    printf("\nafter delete :");
    print();
}