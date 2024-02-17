#include<stdio.h>
int main ()
{    char str1[100],str2[100];
      int i=0,j=0;
     printf("enter first string \n");
     fgets(str1,sizeof(str1),stdin);
     printf("enter second string \n");
     fgets(str2,sizeof(str2),stdin);


      while(str1[i]!='\0' && str2[i]!='\0')
      {
          if(str1[i]!=str2[i])
          printf("difference betwwn mismach cghracater %d \n",str1[i]-str2[i]);
           i++;

      }

      if (str1[i]!='\0' || str2[i]!='\0')
      {     printf("difference betwwn mismach cghracater %d \n",str1[i]-str2[i]);

      }
      else 
      printf("strings are equal\n");


}