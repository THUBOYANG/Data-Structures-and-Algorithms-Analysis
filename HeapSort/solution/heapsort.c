#include<stdio.h>
//所有函数几乎与课件上伪代码一样
void sift(int *T,int n,int i)
{
    int k=i;
    int val=T[i];
    int j=-1;
    int L;
    while(j!=k)
    {
        j=k;
        if(2*j+2<=n)
        {
            L=1;
            if(2*j+2<n&&T[2*j+2]>T[2*j+1])
                L=2;
            if(T[2*j+L]>val)
            {
                T[k]=T[2*j+L];
                k=2*j+L;
            }
        }
    }
    if(k!=i)
        T[k]=val;
}

void make_heap(int *T,int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
        sift(T,n,i);
    }
}

void heap_sort(int *T,int n)
{
    make_heap(T,n);
    int i,temp;
    for(i=n-1;i>=1;i--)
    {
        temp=T[i];
        T[i]=T[0];
        T[0]=temp;
        sift(T,i,0);
    }
}

int main()
{
    int *T;
    int n,i;
    scanf("%d",&n);
    T=(int*)malloc(sizeof(int)*n);
    if(T==NULL) exit(1);
    for(i=0;i<n;i++)
        scanf("%d",&T[i]);
    heap_sort(T,n);
    for(i=0;i<n;i++)
        printf("%d ",T[i]);
    return 0;
}
