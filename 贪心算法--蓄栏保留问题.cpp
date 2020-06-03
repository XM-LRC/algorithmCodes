/**
求解蓄栏保留问题。农场有n头牛，
每头牛会有一个特定的时间区间[b，e]在蓄栏里挤牛奶，
并且一个蓄栏里任何时刻只能有一头牛挤奶。
现在农场主希望知道最少设置多少个蓄栏能够满足上述要求，
并给出每头牛被安排的方案。对于多种可行方案，输出一种即可。

*/


#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAXN 20
struct Cow
{
    int no;  // 牛的编号
    int b;   // 开始时间
    int e;
    bool operator<(const Cow &s)const
    {
        if(e==s.e)
            return b<=s.b;   // 如果结束时间相同，开始时间递增
        else
            return e<=s.e;   // 结束时间递增排序
    }
};

int n=5;
Cow A[]={{0},{1,2,3},{2,3,4},{3,5,6},{4,7,8},{5,8,10}};

int ans[MAXN];   // 存放解向量

void solve()
{
    sort(A+1,A+n+1);
    memset(ans,0,sizeof(ans));   // 初始化解向量
    int num=1;                   // num表示蓄栏的数量

    for(int i=1;i<=n;i++)
    {
        if(ans[i]==0)
        {
            ans[i]=num;          // num表示蓄栏的数量
            int preend=A[i].e;   // 保留结束时间
            for(int j=i+1;j<=n;j++)
            {
                if(A[j].b>preend&&ans[j]==0)
                {
                    ans[j]=num;
                    preend=A[j].e;
                }

            }
            num++;
        }
    }
    cout<<"蓄栏的数量为:"<<num<<endl;
}

int main()
{
    solve();
    return 0;
}
