#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000 // 最大顶点数
#define MAXM 1000000 // 最大边数
int f[MAXM]; // from
int t[MAXM]; // to
int c[MAXM]; // cost
int h[MAXM]; // heap
int hsize = 0; // heap的大小
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
            if(2*j+2<n&&c[T[2*j+2]]<c[T[2*j+L]])
                L=2;
            if(c[T[2*j+L]]<c[val])
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

typedef struct
{
    int size;
    int *h;
    int *set;
} Disjset;
Disjset *disjset;
void disjset_init(int size){
    int i;
    disjset = malloc(sizeof(Disjset));
    disjset->size = size;
    disjset->h = malloc(sizeof(int)*size);
    disjset->set = malloc(sizeof(int)*size);
    for(i=0;i<size;++i){
        disjset->h[i] = 1;
        disjset->set[i] = i;
    }
}
int disjset_find(int x){
    int r = x, i = x, j;
    // 找到根节点
    while(disjset->set[r] != r)
        r = disjset->set[r];
    // 压缩路径
    while(disjset->set[i] != r){
        j = disjset->set[i];
        disjset->set[i] = r;
        i = j;
    }
return r;
}

int disjset_merge(int a, int b){
    if(disjset->h[a] == disjset->h[b]){
        disjset->set[b] = a;
        ++disjset->h[a];
    }
    else if(disjset->h[b] < disjset->h[a]){
        disjset->set[b] = a;
    }
    else{
        disjset->set[a] = b;
    }
}

int main()
{
    int n, m, i, j, a, b;
    int sum = 0, count = 0;
    scanf("%d %d", &n, &m);
    for(i=0;i<m;++i){
        scanf("%d %d %d", &f[i], &t[i], &c[i]);
        --f[i];
        --t[i];
        h[hsize++] = i;
    }
    make_heap(h,hsize); // 建立heap
    disjset_init(n); // 初始化结构体
    for(i=0;i<m;++i){
        j = h[0];
        --hsize;
        // 将堆末尾元素存到顶部，然后sift
        h[0] = h[hsize];
        sift(h,hsize,0);
        a = disjset_find(f[j]);
        b = disjset_find(t[j]);
        if(a != b){
            ++count;
            sum += c[j];
            c[j] = -c[j]; // 将c[j]取负来表示该边被选取
            disjset_merge(a, b);
        }
        if(count == n-1)
            break;
    }
printf("%d\n", sum);
return 0;
}
