#include <stdio.h>
#include <time.h> // ʱ����ص�ͷ�ļ�
void insertion_sort(int a[],int n)//�������򷨺���
{
     int i,j,temp;
     for (i = 1; i < n; i++)
     {
         if (a[i - 1] > a[i])
         {
             int temp = a[i];
             int j = i;
             while (j > 0 && a[j - 1] > temp)
             {
                a[j] = a[j - 1];
                j--;
             }
             a[j] = temp;
         }
     }
}
int main ()
{
clock_t t; // ������¼ʱ��ı���
int n,i;
int a[10000];
float sum = 0;
int repeat, repeat_times = 100; // �����ظ������ı���
scanf("%d",&n);//���������ģ
for(repeat=0; repeat<repeat_times; ++repeat)// Ϊ����߽���ľ��ȣ�ͨ����Ҫ�ظ�����ȡ��ֵ
{
    for(i=0;i<n;i++)
    {
       a[i]=rand()%1001;//���ɹ�ģΪn���������
    }
    t = clock();// �ڲ����Ĵ��뿪ʼ����֮ǰ����¼��clock() �ķ���ֵ����Ϊ�������еĿ�ʼʱ��
    insertion_sort(a,n);//�����������
    t = clock() - t; // �ڲ����Ĵ������н������õ�ǰʱ���ȥ��ʼʱ�䣬�õ���������Ҫ��ʱ��
    sum = t + sum;//�ۼƺ�ʱ
}
printf("It took %f seconds to run insertion_sort(%d)\n", ((float)sum)/CLOCKS_PER_SEC/repeat_times); // ��clock_t ת�����벢�����ظ�����
return 0;
}
