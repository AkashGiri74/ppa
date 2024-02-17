//anagram string or not
/*An anagram of a string is another string that contains the same characters, only the order of characters can be different.
*/ 
#include<stdio.h>
int  main ()
{char str1[100],str2[100];
 int flag=0,i=0,j=0,count1=0,count2=0,length1=0,length2=0;
  printf("enter string1: ");
  fgets(str1,sizeof(str1),stdin);
  printf(" string 1 %s",str1);
   printf("enter string2: ");
  fgets(str2,sizeof(str2),stdin);
   printf(" string 2 %s",str2);

//find length of the both strings 
  while(str1[i]!='\n')
  {
   i++;
   length1++;

  } 
  i=0;
  while(str2[i]!='\n')
  {
   i++;
   length2++;

  }
  if (length1!=length2)
  {
    printf("strings are not anagaram" );
    flag=1;
  }
  else
  { i=0;
     while(str1[i]!='\n')
     {   j=0;
         count1=0;
         count2=0;
         while(str1[j]!='\n')
         {
            if (str1[i]==str1[j])
            {count1++;
            }
             j++;
         } 

         j=0;
         while(str2[j]!='\n')
         {
            if (str1[i]==str2[j])
            {count2++;
            }
           j++;
         } 

         if (count1!=count2)
         {
            printf("strings are not anagarm\n");
            break;
            flag=1;

         }
        i++;
     }
  }

  if (flag==0)
    {    printf("string are anagram\n");
    }
}
 
 