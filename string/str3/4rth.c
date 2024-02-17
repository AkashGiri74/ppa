#include<stdio.h>
int main ()
{    char str1[100],str2[100];
      int i=0,j=0,n;
     printf("enter first string \n");
     fgets(str1,sizeof(str1),stdin);
     printf("enter second string \n");
     fgets(str2,sizeof(str2),stdin);
     printf("enter how many elements you want two compare\n");
     scanf("%d",&n);



      while(str1[i]!='\0' && str2[i]!='\0' && i<n)
      {
          if(str1[i]!=str2[i])
          printf("difference betwwn mismach cghracater %d \n",str1[i]-str2[i]);
           i++;

      }
       
    if (i == n) {
        printf("Both strings are equal till the first %d characters.\n", n);
    } else {
        printf("Difference between first mismatch character: %d\n", str1[i] - str2[i]);
    }


}