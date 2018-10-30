#include <stdio.h>
#include <time.h> // 时间相关的头文件
void insertion_sort(int a[],int n)//插入排序法函数
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
                j--; /* 从右向左找第一个小于x的数 */
            if(i < j)
                s[i++] = s[j];


            while(i < j && s[i] < x)
                i++; /* 从左向右找第一个大于x的数 */
            if(i < j)
                s[j--] = s[i];

        }
        s[i] = x;
        quick_sort(s, l, i-1); /* 递归调用 */
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
clock_t t; // 用来记录时间的变量
int n,i;
int a[10000],temp[10000];
float sum = 0;
int repeat, repeat_times = 100; // 用于重复测量的变量
scanf("%d",&n);//输入数组规模
for(repeat=0; repeat<repeat_times; ++repeat)// 为了提高结果的精度，通常需要重复运行取均值
{
    for(i=0;i<n;i++)
    {
       a[i]=rand()*1001;//生成规模为n的随机数组
    }
    t = clock();// 在测量的代码开始运行之前，记录下clock() 的返回值，作为代码运行的开始时间
    //insertion_sort(a,n);
    quick_sort(a,0,n-1);
    //mergesort(a,0,n-1,temp);//运行排序代码
    t = clock() - t; // 在测量的代码运行结束后，用当前时间减去开始时间，得到运行所需要的时间
    sum = t + sum;//累计耗时
}
printf("It took %f seconds to run insertion_sort(%d)\n", ((float)sum)/CLOCKS_PER_SEC/repeat_times); // 将clock_t 转换成秒并除以重复次数

}
