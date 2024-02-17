#include<stdio.h>
int main ()
{
  char str[200];
  int i,lastspace=-1;//we need to initialize last space as -1
  printf("enter a string:");
  fgets(str,sizeof(str),stdin);

  //we need to find last space 
    for(i=0;str[i]!='\0';i++)
       { if (str[i]==' ')
          lastspace=i;
      }

    if (lastspace!=-1)
    {
        printf("lastword =%s ",str+lastspace+1);//here str is base address 
                                                //last sapce is is last lastspace 
                                                //+1 is word after last sapce
    }  
    else //if there is no space 
    printf(" last word : %s",str);

        



}