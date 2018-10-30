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
void quick_sort(int s[], int l, int r)
{
    int i, j, x;
    if (l < r)
    {
        i = l;
        j = r;
        x = s[i];
        while (i < j)
        {
            while(i < j && s[j] > x)
                j--; /* ���������ҵ�һ��С��x���� */
            if(i < j)
                s[i++] = s[j];


            while(i < j && s[i] < x)
                i++; /* ���������ҵ�һ������x���� */
            if(i < j)
                s[j--] = s[i];

        }
        s[i] = x;
        quick_sort(s, l, i-1); /* �ݹ���� */
        quick_sort(s, i+1, r);
    }
}

void mergearray(int a[], int first, int mid, int last, int temp[])
{
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;
    if(n < 1)
        return;
    while (i <= m && j <= n)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= n)
        temp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(a, first, mid, temp);
        mergesort(a, mid + 1, last, temp);
        mergearray(a, first, mid, last, temp);
    }
}
int main ()
{
clock_t t; // ������¼ʱ��ı���
int n,i;
int a[10000],temp[10000];
float sum = 0;
int repeat, repeat_times = 100; // �����ظ������ı���
scanf("%d",&n);//���������ģ
for(repeat=0; repeat<repeat_times; ++repeat)// Ϊ����߽���ľ��ȣ�ͨ����Ҫ�ظ�����ȡ��ֵ
{
    for(i=0;i<n;i++)
    {
       a[i]=rand()*1001;//���ɹ�ģΪn���������
    }
    t = clock();// �ڲ����Ĵ��뿪ʼ����֮ǰ����¼��clock() �ķ���ֵ����Ϊ�������еĿ�ʼʱ��
    //insertion_sort(a,n);
    quick_sort(a,0,n-1);
    //mergesort(a,0,n-1,temp);//�����������
    t = clock() - t; // �ڲ����Ĵ������н������õ�ǰʱ���ȥ��ʼʱ�䣬�õ���������Ҫ��ʱ��
    sum = t + sum;//�ۼƺ�ʱ
}
printf("It took %f seconds to run insertion_sort(%d)\n", ((float)sum)/CLOCKS_PER_SEC/repeat_times); // ��clock_t ת�����벢�����ظ�����

}
