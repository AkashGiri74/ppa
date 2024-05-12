//hash table oprations
#include<stdio.h>
#include<stdlib.h>
#define size 7
int arr[size];
int init()
{
    for(int i=0;i<size;i++)
    {
        arr[i]=-1;
    }
}
int insert(int value)
{
    int key=value%size;
    if(arr[key]==-1)
    {
        arr[key]=value;
        printf("%d is inserted at %d\n",value,key);
    }
    else
    {
        printf("collision occur unable to insert %d\n",value);
    }
}
int print()
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
int s(int value)
{
  int  key=value%size;
    
    if(arr[key]==value)
    {
        printf("%d found at index %d",value,key);
    }
    else
    {
        printf("not found\n");
    }
}
int delt(int value)
{
    int key=value %size;
    if(arr[key]==value)
    {
      arr[key]=-1;
    }
}
int main()
{  int value;
    init();
   insert(10);//10% 7==3
   insert(8);//=1
   insert(7);//=0
   insert(4);//2
   insert(2);//6
   printf("after inserting:");
   print();
    
    
    printf("\nenter element to search :");
    scanf("%d",&value);
    s(value);
     int del;
    printf("enter element to dlete:");
    scanf("%d",&del);
    delt(del);
    printf("after delete:");
    print();

}