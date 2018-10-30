#include<stdio.h>
#define scale 1001
void showpost(int* pre,int* mid,int n)
{
    if(n>=2){
        int i,t=0;
        for(i=0;i<n;i++){
            if(pre[0]==mid[i]){
                t=i;
                break;
            }
        }
        showpost(pre+1,mid,t);
        showpost(pre+t+1,mid+t+1,n-t-1);
        printf("%d ",pre[0]);
    }
    else if(n==1)
        printf("%d ",pre[0]);
    else
        return;
}

int main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    int pre[scale],mid[scale];
    for(i=0;i<n;i++)
        scanf("%d",&pre[i]);
    for(i=0;i<n;i++)
        scanf("%d",&mid[i]);
    showpost(pre,mid,n);
    return 0;
}


