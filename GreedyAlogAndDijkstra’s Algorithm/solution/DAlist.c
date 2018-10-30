#include <stdio.h>
#include <time.h>

#define INF 1000001 // 表示无穷大
#define N 1000
#define M 1000000
int p[N+1]; // 指针数组
int t[M]; // to数组
int L[M]; // 边长
int d[N]; // 起点到每个点距离
int main()
{
    int n,m,from,s,i,j,k,minj;
    scanf("%d %d", &n, &m);

    for(i=0;i<n;i++)//初始化d
        d[i]=0;
    for(i=0;i<m;i++){
        scanf("%d %d %d", &from, &t[i], &L[i]);
        from--;
        t[i]--;
        if(d[from]==0){
            d[from]=INF;
            p[from]=i;
        }
    }
    p[n]=m;
    s=0; // 起点
    d[s]=0; // 起点到起点的距离为0
    //初始化跟起点相邻的点与起点距离
    for(k=p[s];k<p[s+1];k++)
        d[t[k]]=L[k];
    for(i=1;i<n;i++){
        minj=-1;
        for(j=0;j<n;j++)
            if(d[j]>0&&(minj<0||d[j]<d[minj])) // 如果该点没有标号、而且距离最短
                minj=j; // 则更新minj
    //修改minj以后的点到起点距离
        for(k=p[minj];k<p[minj+1];k++)
            if(d[minj]+L[k]<d[t[k]])
                d[t[k]]=d[minj]+L[k];
        d[minj]=-d[minj]; // 表示minj已经最优
    }
    for(j=0;j<n;j++)
        printf("%d ", -d[j]);
    return 0;
}
