#include <stdio.h>
#include <time.h>

#define INF 1000001 // ��ʾ�����
#define N 1000
#define M 1000000
int p[N+1]; // ָ������
int t[M]; // to����
int L[M]; // �߳�
int d[N]; // ��㵽ÿ�������
int main()
{
    int n,m,from,s,i,j,k,minj;
    scanf("%d %d", &n, &m);

    for(i=0;i<n;i++)//��ʼ��d
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
    s=0; // ���
    d[s]=0; // ��㵽���ľ���Ϊ0
    //��ʼ����������ڵĵ���������
    for(k=p[s];k<p[s+1];k++)
        d[t[k]]=L[k];
    for(i=1;i<n;i++){
        minj=-1;
        for(j=0;j<n;j++)
            if(d[j]>0&&(minj<0||d[j]<d[minj])) // ����õ�û�б�š����Ҿ������
                minj=j; // �����minj
    //�޸�minj�Ժ�ĵ㵽������
        for(k=p[minj];k<p[minj+1];k++)
            if(d[minj]+L[k]<d[t[k]])
                d[t[k]]=d[minj]+L[k];
        d[minj]=-d[minj]; // ��ʾminj�Ѿ�����
    }
    for(j=0;j<n;j++)
        printf("%d ", -d[j]);
    return 0;
}
