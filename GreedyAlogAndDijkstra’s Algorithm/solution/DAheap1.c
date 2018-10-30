#include<stdio.h>

#define N 1000 //顶点数上界
#define M 1000000 //边数上界
#define INF 1000001  //表示无穷大
int p[N+1]; // 指针数组
int t[M]; // to数组
int L[M]; // 边距
int d[N]; // 起点到每个点距离
int pos[N]; // 记录顶点在heap中的位置
int h[N]; // heap顶点编号
int size; // heap的大小

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
            if(2*j+2<n&&d[T[2*j+2]]<d[T[2*j+1]])
                L=2;
            if(d[T[2*j+L]]<d[val])
            {
                T[k]=T[2*j+L];
                pos[T[k]]=k;
                k=2*j+L;
            }
        }
    }
    if(k!=i){
        T[k]=val;
        pos[T[k]]=k;
    }
}

void make_heap(int *T,int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
        sift(T,n,i);
    }
}

void percolate(int *T,int i){
    int k = i;
    int val = T[i];
    int j = -1;
    while(j!=k){
        j = k;
        if(j>0&&d[T[(j-1)/2]]>d[val]){
             k = (j-1)/2;
             T[j] = T[k];
             pos[T[j]] = j;
        }
    }
    if(k!=i){
    T[k] = val;
    pos[T[k]] = k;
    }
}
int main(){

    int n,m,from,s,i,j,k,minj;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++)//初始化d
        d[i]=0;
    for(i=0;i<m;i++)
    {
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
    for(k=p[s];k<p[s+1];k++){
        d[t[k]]=L[k];
        h[size]=t[k];
        pos[t[k]]=size;
        size++;
    }
    make_heap(h,size);
    for(i=1;i<n;i++){
        minj=h[0];
        size--;
        h[0]=h[size];
        pos[h[0]]=0;
        sift(h,size,0);
        //修改minj以后的点到起点的距离
        for(k=p[minj];k<p[minj+1];k++){
            if(d[minj]+L[k]<d[t[k]]){
                if(d[t[k]]==INF){
                    h[size]=t[k];
                    pos[t[k]]=size;
                    size++;
                }
                d[t[k]]=d[minj]+L[k];
                percolate(h,pos[t[k]]);
            }
        }
    }
    for(j=0;j<n;j++)
        printf("%d ",d[j]);
    return 0;

}

