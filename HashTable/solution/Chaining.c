#include<stdio.h>
#include<string.h>

//��ϣ��ṹ��
struct hashtable{
    char name[17];
    int score;
    struct hashtable*next;
};
//������ϣ��
struct hashtable ht[10001];
//����hash����djb2
unsigned long hash(unsigned char *str){
    unsigned long hash = 5381;
    int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c;
    return hash;
}

//���빦�ܺ���insert
int insert(char *name,int score)
{
    int h=hash(name)%10001;//�ҵ�λ��
    struct hashtable*p=malloc(sizeof(struct hashtable));//�����ڵ�
    p->score=score;
    strcpy(p->name,name);
    //���½ڵ�嵽ͷ��
    p->next=ht[h].next;
    ht[h].next=p;
    return score;
}

//���ҹ��ܺ���search
int search(char *name)
{
    int h=hash(name)%10001;
    struct hashtable*p=ht[h].next;
    while(p){
        if(strcmp(p->name,name)==0)//�ж��ǲ���Ҫ�ҵ�����
            return p->score;
        p=p->next;
    }
    return -1;//δ�ҵ�����-1
}

//ɾ�����ܺ���delete
int ht_delete(char *name)
{
    int score=-1;
    int h=hash(name)%10001;
    struct hashtable*p1=&ht[h];
    struct hashtable*p2;
    while(p1->next){
        p2=p1->next;
        if(strcmp(p2->name,name)==0){
            score=p2->score;
            p1->next=p2->next;//ɾ��p2
            break;
        }
        p1=p2;
    }
    return score;
}

int main()
{
    int i,n,score;
    char operation;
    char name[17];
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf(" %c %s", &operation, name);
        if(operation=='i')
            scanf("%d", &score);
        switch(operation)
        {
        case 'i':
            score=insert(name,score);
            printf("i %s %d\n", name, score);
            break;
        case 's':
            score=search(name);
            printf("s %s %d\n", name, score);
            break;
        case 'd':
            score=ht_delete(name);
            printf("d %s %d\n", name, score);
            break;
        }
    }
}
