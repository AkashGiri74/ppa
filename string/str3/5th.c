#include<stdio.h>
int main ()
{ char str1[100],str2[100],char1,char2;
      int i=0;
     printf("enter first string\n");
     fgets(str1,sizeof(str1),stdin);

  printf("enter second string\n");
     fgets(str2,sizeof(str2),stdin);
     //we need two convert it
     while(str1[i]!='\0' &&str2[i]!='\0')
     {   char1=str1[i];
         char2=str2[i];
         if (char1 >='A' && char1 <='Z')
         { 
            char1+=32;
           }
         if (char2>='A' && char2<='Z')
         { 
            char2+=32;//convert upper two lower
           }

        if (char1 != char2) 
        {
            printf("Difference between first mismatch character: %d\n", char1 - char2);
            
        }

       i++;
     }
     if(str1[i]!='\0' || str2[i]!='\0')
     {
        printf("Difference between first mismatch character: %d\n",str1[i]-str2[i]);
     
     }
     else
     {
        printf("strings are equal\n");
     }


}