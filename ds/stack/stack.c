#include<stdio.h>
#include<stdlib.h>
struct STACK
{
    int *arr;
    int top;
    int capacity;

};

int is_underflow(struct STACK * stack);
int is_overflow(struct STACK * stack);
struct STACK * create_stack()
{   int cap;
    struct STACK * stack=NULL;
    stack=(struct  STACK *)malloc(sizeof(struct  STACK));
    if (stack==NULL)
    {
    puts("error in memeory allocation");
    exit(EXIT_FAILURE);
    }
    
    else
    {  printf("enter capacity");
    scanf("%d",&cap);
       stack->capacity=cap;
       stack->arr=(int *)malloc(stack->capacity*sizeof(int ));
       if (stack->arr==NULL)
       {
        puts("error in memory allocation");
        exit(EXIT_FAILURE);
       }
       stack->top=-1;
    }
   return stack;
    
}
void push(struct STACK * stack)
{
       int data;
       printf("enter data :");
       scanf("%d",&data);

     if(  is_overflow(stack))
     {
        puts("stack is overflow");
        return;
     }
     else
     { 
        ++(stack->top);
        stack->arr[stack->top]=data;
     }
}
int is_overflow(struct STACK * stack)
{
    return stack->top==stack->capacity-1;
}
void display(struct STACK * stack )
{
int i;
if(is_underflow(stack))
{
    puts("stack underflow");
    return;
}
for(i=0;i<=stack->top;i++)
{
    printf("%d ",stack->arr[i]);
}
printf("\n");
}
void pop (struct STACK * stack)
{
    if(is_underflow(stack))
    {
      puts("stack undeflow");
      exit(EXIT_FAILURE);
    }
    else
    {
        printf("pop element :%d \n",stack->arr[stack->top]);
        (stack->top)--;
    }
}
int is_underflow(struct STACK * stack)
{
  return stack->top==-1;
}
int  main ()
{
    struct STACK* stack=NULL;
    int choice;
      stack=create_stack();
    do
    {
         printf("1.push ");
         printf("2.pop ");
         printf("3.display ");
         printf("enter your choice :");
         scanf("%d",&choice);
         switch (choice)
         {
         case 1:push(stack);
            break;
         case 2:pop(stack);
            break;
          case 3:display(stack);
          break;
         }
    } while (choice !=0);
    
}