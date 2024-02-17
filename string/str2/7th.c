#include<stdio.h>
int main ()
{
  char str[100],i;
  printf("enter a string: ");
  fgets(str,sizeof(str),stdin);

  for(i=0;str[i]!='\0';i++)
  { if (str[i]>='a' && str[i]<='z')
      str[i]-=('a'-'A');

  }

printf("string in upper case: %s",str);


}