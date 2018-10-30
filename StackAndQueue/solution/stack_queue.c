#include<stdio.h>
//用s[0]表示栈里元素个数
int s1[1001],s2[1001];
void push(int s[],int x){
    s[0]=s[0]+1;
    s[s[0]]=x;
}
int pop(int s[]){
    s[0]=s[0]-1;
    return s[s[0]+1];
}
void enqueue(int x){
    push(s1,x);
}
int dequeue(){
    if(s2[0]==0){
        while(s1[0]>0)
            push(s2,pop(s1));
    }
    return pop(s2);
}
int main(){
    int n,i;
    int x[1001];
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &x[i]);
        if(x[i]>=0)
            enqueue(x[i]);
        else
            printf("%d %d\n", i+1, dequeue());
    }
}
