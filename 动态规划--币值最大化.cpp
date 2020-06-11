
#include<iostream>
using namespace std;
#define max(x,y)  (x>y)?x:y

// 获取最大价值
int solve(int *coin,int *before,int num)
{
    // 初始化条件
    before[0] = 0;
    before[1] = coin[1];

    for (int i = 2; i <= num ; i++)
    {
        before[i] = max(coin[i]+before[i-2],before[i-1]);
    }
    return before[num];
}

// 选择满足条件的硬币，即回退回去看before的取值
void backChoose(int *choice,int *before,int *coin,int n)
{
    int k = 0;
    for (int i = n; i >= 1; i--)
    {
        if (before[i] == before[i - 1])
        {
            choice[k++] = coin[--i]; //若选择前面那个，则将前面那个硬币放入
        }

        else
        {
            choice[k++] = coin[i--];//没有选择前面那个，将自身放入

        }
    }
    for (int i = 0; i < k;i++)
        cout<<choice[i]<<"  ";
    cout<<endl;
}

int main()
{
    int num ;
    cout<<"请输入有多少个硬币:";
    cin>>num;
    int coin[num+1];
    cout<<"请输入硬币的价值:";
    for (int i = 1;i <=num ; i++)
    {
        cin>>coin[i];
    }
    int before[num+1];
    int maxValue = solve(coin,before,num); // 去最大价值
    int choice[num+1];
    cout<<"选择的硬币如下:";
    backChoose(choice,before,coin,num);   // 选择硬币
    cout<<"最大价值为:"<<maxValue<<endl;
}
