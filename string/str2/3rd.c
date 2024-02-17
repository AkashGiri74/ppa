// print odd even words

#include<stdio.h>
int main ()
{
  char str[20];
  int i,even=0,odd=0,length=0;
  printf("enter a string:");
  fgets(str,sizeof(str),stdin);

  for (i=0;str[i]!='\0';i++)
     {  if (str[i]==' ')
        
        {   if (length%2==0)
              { 
                even++;
              }
             else
             { 
                 odd++;   
             }
               //reset word length  needed
             length=0;
        }
        else
        length++;//if there is no space present 
     }

 //there is no space for last word so  
 if (length%2==0)
 {
      even++;
 }
 else
 {
     odd++;
 }

printf("odd words =%d ,even words=%d",odd,even);



}