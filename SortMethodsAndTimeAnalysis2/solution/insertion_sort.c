#include<stdio.h>
void insertion_sort(int a[],int n)
{
     int i,j,temp;
     for (i = 1; i < n; i++)
     {
         if (a[i - 1] > a[i])
         {
             int temp = a[i];
             int j = i;
             while (j > 0 && a[j - 1] > temp)
             {
                a[j] = a[j - 1];
                j--;
             }
             a[j] = temp;
         }
     }
}
int main()
{
    int n,i;
    int a[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    insertion_sort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
