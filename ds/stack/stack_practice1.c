#include<stdio.h>
#include<stdlib.h>
struct  STACK
{
    int * arr;
    int capacity;
    int top;
};

 struct STACK * create_stack()
{   int cap;
    struct STACK * stack;
    stack=(struct STACK*)malloc(sizeof(struct STACK));
    if (stack==NULL)
    {
        puts("error in memory allocation");
        exit(EXIT_FAILURE);
    }
    else
    {   printf("enter capacity :");
        scanf("%d",&cap);
        stack->capacity=cap;
        stack->arr=(int *)malloc(stack->capacity*sizeof(int));
        if (stack->arr==NULL)
        {
            puts("error in memory allocation");
            exit(EXIT_FAILURE);
        }
        stack->top=-1;
        return stack;
    }
}
int is_overflow(struct STACK * stack)
{
    return stack->top==stack->capacity-1;
}
void push(struct STACK * stack)
{     int data;

     printf("enter data");
     scanf("%d",&data);

    if(is_overflow(stack))
    {
        printf("stack is overflow");
        return;
    }
    else
    {  ++(stack->top);
       stack->arr[stack->top]=data;

    }
}
int is_underflow(struct STACK * stack)
{
    return stack->top==-1;
}
void pop(struct STACK * stack)
{
    if (is_underflow(stack))
    {
        printf("stack is empty");
        return;
    }
    else
    {     printf("poped element is %d ",stack->arr[stack->top]);
            (stack->top)--;

    }
}
void display(struct STACK * stack)
{
    if (is_underflow(stack))
    {
        printf("stack is empty");
        return;
    }
    else
    {
        int i;

        for(i=0;i<=stack->top;i++)
        {
            printf("%d ",stack->arr[i]);
        }
    }
}
int peek(struct STACK * stack)
{
    if (is_underflow(stack))
    {
        printf("stack is empty");
        exit(EXIT_FAILURE);

    }
    else{
      return stack->arr[stack->top];
    }

    
}
int main ()
{
    struct STACK * stack=NULL;
    stack=create_stack();
    int choice;

    do
    {
        puts("1.push");
        puts("2.pop ");
        printf("3.peek ");
        puts("4.display");

        printf("enter your choice :");
        scanf("%d",&choice);
         switch (choice)
         {
         case 1:push(stack);
            break;
         case 2:pop(stack);
             break;
         case 3 :printf("top elemt %d ",peek(stack));
              break;   
         case 4:display(stack);
              break;         
         }

    } while (choice!=0);
    
}