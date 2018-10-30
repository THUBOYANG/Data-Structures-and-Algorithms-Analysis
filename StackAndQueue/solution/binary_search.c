#include<stdio.h>
int main(){
    int n,i,x,j;
    int *a=(int*)malloc(sizeof(int)*1000001);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }
    scanf("%d",&x);
    int head=0,tail=n;
    while(tail>head){
        j=(head+tail)/2;
        if(a[j]==x){
           printf("%d",j+1);
           break;}
        else if(a[j]>x)
           tail=j;
        else
           head=j+1;
    }
    if(a[j]!=x)
       printf("%d",-1);
}
