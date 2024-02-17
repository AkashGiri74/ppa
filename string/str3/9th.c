#include<stdio.h>
int main ()
{
  char str[100];
  int i,length;
  printf("enter a string:");
  gets(str);
  for(i=0;str[i]!='\0';i++)
          length++;
  
  // length=strlen(str);
  for(i=0;i<length/2;i++)
    {  
        if (str[i]!=str[length-1-i])
          {  printf("not palindrome\n");
              break;
          }

    }
    if (i==length/2)
         printf("palindrome\n");        


}


/*#include <stdio.h>

int main() {
    char inputString[100];
    int isPalindrome;
    int start;
    int end ,length;

    printf("Enter a string: ");

    
    fgets(inputString, sizeof(inputString), stdin);


     length = 0;
    while (inputString[length] != '\0') {
        if (inputString[length] == '\n') {
            inputString[length] = '\0';
            break;
        }
        length++;
    }

    isPalindrome=1;
    start=0;
    end=length-1;

    
    while (start < end) 
    {
        if (inputString[start] != inputString[end])
         {
            isPalindrome = 0;
            break;
        }
        start++;
        end--;
    }


    if (isPalindrome)
     {
        printf("String is palindrome.\n");
    } else
     {
        printf("String is not palindrome.\n");
    }


}*/
