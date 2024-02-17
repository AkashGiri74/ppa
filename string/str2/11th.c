#include<stdio.h>
int main ()
{   char str1[100],str2[100];
     int n,length,i;
      printf("enter string:");
      fgets(str1,sizeof(str1),stdin);
      printf("how many characater you last wnat to copy\n");
      scanf("%d",&n);
      i=0;
      while(str1[i]!='\0')
      {  i++;
        length++;

      }


      for(i=0;i<n && str1[i]!='\0';i++)
      {
        
          str2[i]=str1[length-n+i];
      } str2[i]='\0';
      printf("string after copy last  %d characters : %s",n,str2);


}