//print how many spaces upper lower
#include<stdio.h>
#define max 20
int main ()
{

char str[max];
int i,small=0,capital=0,space=0,digit=0;
printf("enter string: ");
fgets(str,sizeof(str),stdin);// fgets(char *str, int n, FILE *stream) fgets is a file function which accept file as a input 
                            //  stdin:- stdin is a standard input file 
 for (i=0;str[i]!='\0';i++)
    { if(str[i]>='a' && str[i]<='z')
         small++;
      else if (str[i]>='A' && str[i]<='Z')
         capital++;
      else if (str[i]>='0' && str[i]<='9')
          digit++; 
      else if (str[i]==' ')
        space++;    
    } 
 printf("space =%d , digit=%d ,capital =%d ,small=%d ",space ,digit,capital,small);                          



}