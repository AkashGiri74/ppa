#include<stdio.h>
int main ()
{
   char* str=NULL;
   char ch;
   int size=1;

   str=(char *)malloc(sizeof(char));
   *(str +0)='\0';
   do
    {  size ++;
    str=(char *)realloc (str,size *sizeof(char));
    *(str +i)=ch;
    *(str+i+1)='\0';
    i++;

    }while(ch !='\n');

   i=0;
   while(*(str+i)!='\0')
   {
    while(*(str+i)== ' ')
    {
        i++;
    }
    while(*(str+i)==' ' && *(str+i) !='\0')
    {
        printf("%c",*(str+1));
        if(*(str +i+1)== ' ')
        {
            printf(" ");
        }
    }

   }

}