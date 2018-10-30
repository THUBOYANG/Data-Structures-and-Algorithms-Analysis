#include<stdio.h>
void mergearray(int a[], int first, int mid, int last, int temp[])
{
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;
    if(n < 1)
        return;
    while (i <= m && j <= n)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= n)
        temp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(a, first, mid, temp);
        mergesort(a, mid + 1, last, temp);
        mergearray(a, first, mid, last, temp);
    }
}
int main()
{
    int a[100000],temp[100000];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n-1,temp);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}

