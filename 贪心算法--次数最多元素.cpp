/*
求解一个序列中出现次数最多的元素
给定n个正整数，编写程序找出它们中出现次数最多的数，
如果这样的数有多个，输出其中最小的数。

*/
#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
   int n;
   cout<<"该序列的元素个数：";
   cin>>n;
   int a[n],x[n]; // a[n]是存放序列，x[n]存放相同元素的个数
   cout<<"请输入元素：";
   for (int i = 0; i < n ;i++)
      cin>>a[i];
   sort(a,a+n);   // 将所有元素排序


    // 还没处理时，x[n]中所以都是1，表示所有元素出现1次
    for(int i =0 ;i<n;i++)
        x[i]= 1;

   int pre = 0;
   for (int i =1 ;i < n; i++)
   {
       if (a[i] == a[pre])
       {
           x[i] = x [i] + x[pre];   // 如果前一个元素与当前相同，当前x[i] + 1;
           pre = i;
       }
       else {
           pre = i;
           x[pre] = 1;
       }
   }
    cout<<"排序后元素：";
    for (int i =0;i <n;i++)
        cout<<a[i]<<"  ";
    cout<<"\n各出现次数：";
    for(int i =0 ;i<n;i++)
        cout<<x[i]<<"  ";

    // 寻找出现次数最多的那一个的下标
    int max=0;
    for(int i=1;i<n;i++)
    if(x[i]>x[max])
    {
        max=i;
    }

    cout<<"\n出现次数最多的数是: "<<a[max]<<endl;

    return 0;
}
