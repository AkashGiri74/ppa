#include<stdio.h>
int main ()
{   char str1[100],str2[100],i;
     int n;
      printf("enter string:");
      fgets(str1,sizeof(str1),stdin);
      printf("how many characater you wnat to copy\n");
      scanf("%d",&n);
      for(i=0;str1[i]!='\0';i++)
      {
        if(i<n)
          str2[i]=str1[i];
      } str2[i]='\0';
      printf("string after copy %d characters : %s",n,str2);


}