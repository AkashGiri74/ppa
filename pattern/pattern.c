#include<stdio.h>
int one(int row)
{   printf("1st\n");
    int i,j;
    for(i=0;i<row;i++)       // * * * * *
     { for(j=0;j<row;j++)    // * * * * *
        {                    // * * * * *
        printf("* ");        // * * * * *
        }                    // * * * * *
      printf("\n");           
     }
} 
int two(int row) 
{  printf("2nd\n");          
    int i,j;
    for(j=0;j<row;j++)       // * * * * *
    {                        // * * * *
      for(i=0;i<row-j;i++)   // * * *                    
      {                      // * *                    
        printf("* ");        // *
      }
      printf("\n");
    }
}
int three(int row)
{
    printf("third\n");
    int i,j;
   for(j=0;j<row;j++)        // *                          
   {                         // * *
    for(i=0;i<=j;i++)        // * * *
    {                        // * * * *
        printf("* ");        // * * * * *
    }
    printf("\n");
   }
}
int main ()
{   int row;
    printf("enter value of row \n");
    scanf("%d",&row);
    one(row);
    two(row);
    three(row);

}  