#include<stdio.h>
int main ()
{  char str1[100];
int length=0,n,i;
 printf("enter first string\n");
     fgets(str1,sizeof(str1),stdin);
      printf("Enter the value of N: ");
    scanf("%d", &n);

 while(str1[length]!='\0')
 {
    length++;
 }   
 if (n>length) 
 {
    n=length;
    }

    
    for (i=n-1;i>=0;i--) 
    
    {
        printf("%c", str1[i]);
    }

    
    for (i =n;i<length; i++) 
    {
        printf("%c", str1[i]);
    
    }




}