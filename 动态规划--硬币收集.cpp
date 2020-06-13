/**
参考：https://www.cnblogs.com/apex-wzw/p/10784509.html
*/
#include <stdio.h>
#include <iostream>
using namespace std;
#define n 5
#define m 6

// 设置硬币位置，0表示空，1表示有硬币
int Coin[n+1][m+1] =
{
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 1},
    {0, 1, 0, 0, 0, 1, 0}
};

int dp [n+1][m+1] ;  // 用于存放机器人在i行j列的最大硬币个数

void DP()
{
    for (int i =1 ; i <= n ;i++)
    {
        for (int j = 1; j<= m;j++)
        {
            if (dp[i-1][j] >= dp[i][j-1])  // 若左边比上边的个数多
                dp[i][j] = dp[i-1][j] + Coin[i][j]; // 使用左边+当前
            else
                dp[i][j] = dp[i][j-1] + Coin[i][j]; // 使用上边+当前
        }
    }
    cout<<"机器人获取最大硬币个数:"<<dp[n][m];
}

int main(int argc, char *argv[])
{
    DP();
    return 0;
}
