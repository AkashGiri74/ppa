#include<stdio.h>
int main ()
{   char str1[100],str2[100],i;
     
      printf("enter string:");
      fgets(str1,sizeof(str1),stdin);
      
      for(i=0;str1[i]!='\0'&& str1[i]!='\n';i++)
      {
        
          str2[i]=str1[i];
      } str2[i]='\0';
      printf("string after copy: %s",str2);


}