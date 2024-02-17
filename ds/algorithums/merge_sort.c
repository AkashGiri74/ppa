 #include<stdio.h>
 #include<stdlib.h>
 #include<time.h>
 #define TRUE 1
  int show_sub(int *a,int p,int r,const char *msg)
  {  int i;
      if(msg!=NULL)
      puts(msg);
      for(i=p;i<=r;i++)
      {
        printf("a[%d]=%d\n",i,a[i]);
      }
 }
//   void merge_proc(int *a,int p,int q,int r)
// {  int i,j,k;
//     int n1=(q-p)+1;
//     int n2=r-q;
//     int *a1=NULL,*a2=NULL;

//        a1=(int *)malloc(n1*sizeof(int));
//        if (a1==NULL)
//        {
//         puts("erroer \n");
//         exit(EXIT_FAILURE);
//        }

//        a2=(int *)malloc(n2*sizeof(int));
//        if (a2==NULL)
//        {
//         puts("erroer \n");
//         exit(EXIT_FAILURE);
//        }
//        for(i=0;i<n1;i++)
//        {
//         a1[i]=a[p+i];
//        }
//        for(i=0;i<n2;i++)
//        {
//         a2[i]=a[q+1+i];
//        }
//        i=0;
//        j=0;
//        k=0;
//        while(TRUE)
//        { if(a1[i]<a2[j])
//           {
//             a[p+k]=a1[i];
//             i++;
//             k++;
//             if(i==n1)
//             {
//                 while(j<n2)
//                 {
//                     a[p+k]=a2[j];
//                     j++;
//                     k++;
//                 }
//                 break;
//             }
//             else 
//             {
//                   a[p+k]=a2[j];
//                     j++;
//                     k++;

//                     if (j==n2)
//                     {
//                       while(i<n1)
//                       { 
//                         a[p+k]=a1[i];
//                         j++;
//                         k++;

//                       }
//                       break;
//                     }
//               }
          

//           }
//         }  
//  }
void merge_proc(int *a,int p,int q ,int r)
{  int n1=(q-p)+1;
    int n2=r-q;
    int *a1=NULL,*a2=NULL;
    int i,j,k;
     a1=(int *)malloc(n1*sizeof(int));
       if (a1==NULL)
       {
        puts("erroer \n");
        exit(EXIT_FAILURE);
       }

       a2=(int *)malloc(n2*sizeof(int));
       if (a2==NULL)
       {
        puts("erroer \n");
        exit(EXIT_FAILURE);
       }
       for(i=0;i<n1;i++)
       {
        a1[i]=a[p+i];
       }
       for(i=0;i<n2;i++)
       {
        a2[i]=a[q+1+i];
       }
       i=0;j=0;k=0;
      while(i<n1 && j<n2)
      {     if(a1[i]<a2[j])
               {
                a[p+k]=a1[i];
                i++;
                k++;
               }
               else
               {
                a[p+k]=a2[j];
                j++;
                k++;
               }

      }
      while(i<n1)
        {  a[p+k]=a1[i];
           i++;
           k++;

        }
        while(j<n2)
        {  a[p+k]=a2[j];
           j++;
           k++;
        }
    



}
 int main ()
 {
  int a[]={ 90,24,71,92,10,20,30,40,50,15,25,35,45,55,65,75,11,12,45,67};
  int p=4,q=8,r=15;
   show_sub(a,p,r,"before sort\n");
   merge_proc(a,p,q,r);
   show_sub(a,p,r,"after sort\n");
 
 
 
 }
