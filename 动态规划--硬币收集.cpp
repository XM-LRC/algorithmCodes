/**
�ο���https://www.cnblogs.com/apex-wzw/p/10784509.html
*/
#include <stdio.h>
#include <iostream>
using namespace std;
#define n 5
#define m 6

// ����Ӳ��λ�ã�0��ʾ�գ�1��ʾ��Ӳ��
int Coin[n+1][m+1] =
{
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 1},
    {0, 1, 0, 0, 0, 1, 0}
};

int dp [n+1][m+1] ;  // ���ڴ�Ż�������i��j�е����Ӳ�Ҹ���

void DP()
{
    for (int i =1 ; i <= n ;i++)
    {
        for (int j = 1; j<= m;j++)
        {
            if (dp[i-1][j] >= dp[i][j-1])  // ����߱��ϱߵĸ�����
                dp[i][j] = dp[i-1][j] + Coin[i][j]; // ʹ�����+��ǰ
            else
                dp[i][j] = dp[i][j-1] + Coin[i][j]; // ʹ���ϱ�+��ǰ
        }
    }
    cout<<"�����˻�ȡ���Ӳ�Ҹ���:"<<dp[n][m];
}

int main(int argc, char *argv[])
{
    DP();
    return 0;
}
