/*--------------------------------------------------------------------------
                            n皇后问题
--------------------------------------------------------------------------*/

#include<iostream>
#include<math.h>
using namespace std;
int sum=0;
/*--------------------------------------------------------------------------
用来判断是否可以放置皇后,，参考做法
x用来存放解向量
n表示n皇后
t表示行列
--------------------------------------------------------------------------*/
bool isset(int t,int *x,int n)
{
    bool ok = true;
    for (int j = 1; j < t; j++) {
        if (x[t] == x[j] || t - j == fabs(x[t] - x[j])) {
            ok = false;
            break;
        }
    }
    return ok;

}
/*--------------------------------------------------------------------------
回溯法求解
x用来存放解向量
n表示n皇后
t表示行列
--------------------------------------------------------------------------*/
void dfs(int t,int *x,int n)
{
    if(t>n)
        sum++;
    else
    {
        for(int i=1;i<=n;i++)
        {
            x[t] = i;
            if (isset(t,x,n))
                dfs(t+1,x,n);
        }
    }
}

int main()
{
    int n;
    cout<<"请输入：n=";
    cin>>n;
    int x[n];
    dfs(1,x,n);
    cout<<"个数:"<<sum;
    return 0;
}








