#include<stdio.h>

#define N 1000 //�������Ͻ�
#define M 1000000 //�����Ͻ�
#define INF 1000001  //��ʾ�����
int p[N+1]; // ָ������
int t[M]; // to����
int L[M]; // �߾�
int d[N]; // ��㵽ÿ�������
int pos[N]; // ��¼������heap�е�λ��
int h[N]; // heap������
int size; // heap�Ĵ�С

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
    for(i=0;i<n;i++)//��ʼ��d
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
    s=0; // ���
    d[s]=0; // ��㵽���ľ���Ϊ0
    //��ʼ����������ڵĵ���������
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
        //�޸�minj�Ժ�ĵ㵽���ľ���
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

