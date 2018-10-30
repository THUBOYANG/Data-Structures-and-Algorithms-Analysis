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
int main ()
{
clock_t t; // 用来记录时间的变量
int n,i;
int a[10000];
float sum = 0;
int repeat, repeat_times = 100; // 用于重复测量的变量
scanf("%d",&n);//输入数组规模
for(repeat=0; repeat<repeat_times; ++repeat)// 为了提高结果的精度，通常需要重复运行取均值
{
    for(i=0;i<n;i++)
    {
       a[i]=rand()%1001;//生成规模为n的随机数组
    }
    t = clock();// 在测量的代码开始运行之前，记录下clock() 的返回值，作为代码运行的开始时间
    insertion_sort(a,n);//运行排序代码
    t = clock() - t; // 在测量的代码运行结束后，用当前时间减去开始时间，得到运行所需要的时间
    sum = t + sum;//累计耗时
}
printf("It took %f seconds to run insertion_sort(%d)\n", ((float)sum)/CLOCKS_PER_SEC/repeat_times); // 将clock_t 转换成秒并除以重复次数
return 0;
}
