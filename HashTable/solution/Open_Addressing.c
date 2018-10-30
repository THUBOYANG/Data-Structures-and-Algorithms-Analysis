#include<stdio.h>
#include<string.h>

//��ϣ��ṹ��
struct hashtable{
    char name[17];
    int score;
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
//����Linear Probing��������h(k,i)
int hki(unsigned char *k,int i){
    return (hash(k)+i)%10001;
}
//���빦�ܺ���insert
int insert(char *name,int score)
{
    int i;
    for(i=0;i<10001;i++){
        if(ht[hki(name,i)].score<0)
            break;
    }
    if(ht[hki(name,i)].score>=0)
        exit(1);
    ht[hki(name,i)].score=score;
    strcpy(ht[hki(name,i)].name,name);
    return score;
}

//���ҹ��ܺ���search
int search(char *name)
{
    int i;
    for(i=0;i<10001;i++){
        if(ht[hki(name,i)].score>=0 && strcmp(ht[hki(name,i)].name,name)==0)
            break;
        if(ht[hki(name,i)].score==-2)
            break;//����δ��ľ�break����ֹ��ʱ
    }
    if(ht[hki(name,i)].score>=0 && strcmp(ht[hki(name,i)].name,name)==0)
        return ht[hki(name,i)].score;
    else
        return -1;
}

//ɾ�����ܺ���delete
int ht_delete(char *name)
{
    int i;
    int showscore=-1;
    for(i=0;i<10001;i++){
        if(ht[hki(name,i)].score>=0 && strcmp(ht[hki(name,i)].name,name)==0){
            showscore=ht[hki(name,i)].score;
            ht[hki(name,i)].score=-1;
            break;
        }
        if(ht[hki(name,i)].score==-2)
            break;
    }
    return showscore;
}



int main()
{
    //��ʼ����ϣ��
    int i;
    for(i=0;i<10001;i++)
    {
        ht[i].score=-2;//-2��ʾδ�������Ϣ
    }
    int n,score;
    i=0;
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
