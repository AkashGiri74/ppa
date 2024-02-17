#include<stdio.h>
int main ()
{
  char str[100],i;
  printf("enter a string: ");
  fgets(str,sizeof(str),stdin);

  for(i=0;str[i]!='\0';i++)
  { if (str[i]>='A' && str[i]<='Z')
      str[i]+=('a'-'A');

  }

printf("string in lower case: %s",str);


}