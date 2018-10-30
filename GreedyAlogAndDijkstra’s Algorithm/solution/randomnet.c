#include<stdio.h>
#include<time.h>

int main()
{
    int arc[1000][1000];
    int point[1000];

    srand(time(NULL));//生成随机种子
    int n,m,c,cost,i,j,k,count;
    scanf("%d %d %d", &n, &m, &c);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            arc[i][j]=0;}//初始化边为0
    //生成1-n-1环
    for(i=0;i<n;i++){
        cost=rand()%c+1;
        arc[i][(i+1)%n]=cost;
    }
    //再生成其他边
    for(i=n;i<m;i++){
        cost=rand()%c+1;
        j=rand()%n;
        k=rand()%n;
        while(j==k||arc[j][k]>0){
            j=rand()%n;
            k=rand()%n;
        }
        arc[j][k]=cost;
    }
    printf("%d %d\n",n,m);
    count=0;
    for(i=0;i<n;i++){
        point[i]=count;
        for(j=0;j<n;j++){
            if(arc[i][j]>0)
            {
                printf("%d %d %d\n",i+1,j+1,arc[i][j]);
                count++;
            }
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",point[i]+1);
    printf("%d",m+1);
    return 0;
}
