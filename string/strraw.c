#include<stdio.h>
void main()
{
      char  raw_str[100];
      char  input_str[100];
      int i=0,j=0;
      
      printf("enter the raw string\n");
      fgets(raw_str, sizeof(raw_str), stdin);
     printf("raw string is :%s\n", raw_str);

      printf("enter the input string\n");
      fgets(input_str, sizeof(input_str), stdin);
     printf("input string is :%s\n", raw_str);

     while(raw_str[i] != ' ')
     {
        i++;
     }
     
      i++;

      while(input_str[j] != '\n')
      {
        raw_str[i]=input_str[j];
        i++;
        j++;
      }
      
            raw_str[i]='\0';

        printf("output string is %s",raw_str);
}
