#include<stdio.h>
int main ()
{

char str[10];
printf("enter str\n");
fgets(str,sizeof(str),stdin);
printf("%s",str);

}