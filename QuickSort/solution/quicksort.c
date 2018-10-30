#include<stdio.h>
#include<stdlib.h>
void quicksort(int *a,int n)
{
    int i,j,p,temp;
    if(n<2)
        return;
    else{
        p=a[n/2];
        for(i=0,j=n-1;;i++,j--)
        {
            while(a[i]<p)
                i++;
            while(a[j]>p)
                j--;
            if(i>=j)
                break;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        quicksort(a,i);
        quicksort(a+i,n-i);
    }
}

int main()
{
    int n,i;
    scanf("%d", &n);
    int *a=malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    quicksort(a,n);
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    return 0;
}
