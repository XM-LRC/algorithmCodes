/*
某项目组分得了7万元的投资，
现要把这7万元分配给A、B、C三个子项目，
每个项目的利润如下，请给出一种分配方案使总利润最大（单位：万元）。

*/
#include<iostream>
using namespace std;
#define maxn 50


int m = 3, n = 7;	// 3个项目，7万元投资
// 投资收益表
double a[maxn][maxn] =
{
    {0,0,0,0,0,0,0},
    {0, 0.11, 0.13, 0.15, 0.21, 0.24, 0.30, 0.35},
    {0, 0.12, 0.16, 0.21, 0.23, 0.25, 0.24, 0.34},
    {0, 0.08, 0.12, 0.20, 0.24, 0.26, 0.30, 0.35}

};


double dp[maxn][maxn];	   	//设dp[i][j]表示，前i个项目投资j万元能获得的最大利益
double path[maxn][maxn];	//存储路径，记录投资结果


double DP()
{
	// 边界处理
	for(int i = 1;i <= m;i++)
	{
		dp[i][0] = 0;
		path[i][0] = 0;
	}
	for(int j = 1;j <= n;j++)
	{
		dp[1][j] = a[1][j];
		path[1][j] = j;
	}


	for(int i = 2;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			double max_res = 0;
			double max_j = 0;
			for(int k = 0;k <= j;k++)	//找出最大收益
			{
				if(dp[i - 1][k] + a[i][j - k] > max_res)
				{
					max_res = dp[i - 1][k] + a[i][j - k];
					max_j = j - k;	  //记录下该项目在最大利益时投资的钱
					                  //其中，j - k表示该项目投资的钱
				}
			}
			dp[i][j] = max_res;
			path[i][j] = max_j;
		}
	}
	return dp[m][n];  // 返回最大收益
}

int main()
{

	cout <<"最大收益:"<< DP() << "万元" << endl;

	//输出具体方案
	cout << "投资方案：" << endl;
	cout << m << "号公司投资" << path[m][n] << "万元" << endl;
	int r = n - path[m][n];
	for(int i = m - 1;i >= 1;i--)
	{
		cout << i << "号公司投资" << path[i][r] << "万元" << endl;
		r = r - path[i][r];
	}
	return 0;
}
