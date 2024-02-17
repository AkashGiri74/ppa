//no of white spaces
//print how many spaces upper lower
#include<stdio.h>
#define max 20
int main ()
{

char str[max];
int i,space=0;
printf("enter string: ");
fgets(str,sizeof(str),stdin);// fgets(char *str, int n, FILE *stream) fgets is a file function which accept file as a input 
                            //  stdin:- stdin is a standard input file 
 for (i=0;str[i]!='\0';i++)
    { 
       if (str[i]==' ')
        space++;    
    } 
 printf(" no of white space =%d ",space);                          



}