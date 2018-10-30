#include<stdio.h>
#include <stdlib.h>
void pigeonhole_sort(int *a,int n)
{
   int i;
   int j=0;
   int *b=(int*)malloc(sizeof(int)*10000);
   for(i=0;i<10000;i++)
    b[i]=0;
   for(i=0;i<n;i++)
   {
      b[a[i]]+=1;
   }
   for(i=0;i<10000;i++)
   {
      int k=0;
      for(k=0;k<b[i];k++)
      {
         a[j]=i;
         j++;
      }
   }
}
int main()
{
   int n,i;
   scanf("%d",&n);
   int *a = (int*)malloc(sizeof(int)*n);
   for(i=0;i<n;i++)
      scanf("%d",a+i);
   pigeonhole_sort(a,n);
   for(i=0;i<n;i++)
     printf("%d ",a[i]);
   return 0;
}
