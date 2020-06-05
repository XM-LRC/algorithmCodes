/**
假设要在足够多会场里安排一批活动，n个活动编号为1~n，
每个活动有开始时间bi和结束时间ei（1<=i<=n）。
设计一个有效的贪心算法求出最少的会场个数。

*/


#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAXN 20
struct Activity
{
    int no;  // 活动编号
    int b;   // 开始时间
    int e;   // 结束时间

    // 事件的时间是不兼容的
    bool operator<(const Activity &s)const
    {
        if(e==s.e)
            return b<=s.b;   // 如果结束时间相同，开始时间递增
        else
            return e<=s.e;   // 结束时间递增排序
    }
};

int n=5;
Activity A[]={{0},{1,2,3},{2,3,4},{3,5,6},{4,7,8},{5,8,10}};

int x[MAXN];   // 存放解向量

void solve()
{
    sort(A+1,A+n+1);
    memset(x,0,sizeof(x));    // 初始化解向量
    int num=1;                // num表示会场个数

    for(int i=1;i<=n;i++)
    {
        if(x[i]==0)
        {
            x[i]=1;            // 添加到解向量
            int preend=A[i].e; // 保留结束时间
            for(int j=i+1;j<=n;j++)
            {
                if(A[j].b>preend&&x[j]==0)
                {
                    x[j]=num;
                    preend=A[j].e;
                }

            }
            num++;
        }
    }
    cout<<"最少会场的数量为:"<<num<<endl;
}

int main()
{
    cout<<"假设有如下的"<<n<<"个活动"<<endl;
    cout<<"编号   "<<"开始时间"<<"\t\t结束时间"<<endl;
    for (int i =1;i <= n;i++){
        cout<<A[i].no<<"\t"<<A[i].b<<"\t\t"<<A[i].e<<endl;
    }
    cout<<endl;
    solve();
    return 0;
}
