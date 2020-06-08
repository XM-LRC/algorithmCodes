/*
3 5
0 3 7 9 12 13
0 5 10 11 11 11
0 4 6 11 12 12
*/
#include<iostream>
using namespace std;

const int maxn = 100;
int m, n;					//m为商店个数，n为员工个数
int dp[maxn][maxn];
int a[maxn][maxn];			//分配员工数和赢利情况的表
int path[maxn][maxn];		//存储路径，记录分配结果

//设dp[i][j]表示，前i个商店分配j个员工能获得的最大利益值
int DP()
{
	//先处理边界1
	for(int i = 1;i <= m;i++)
	{
		dp[i][0] = 0;
		path[i][0] = 0;
	}
	//边界2
	for(int j = 1;j <= n;j++)
	{
		dp[1][j] = a[1][j];
		path[1][j] = j;
	}

	//再来其他情况，遍历顺序从上到下，从左到右，是常规顺序
	for(int i = 2;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			int max_res = 0;
			int max_j = 0;
			for(int k = 0;k <= j;k++)			//找出最大的那个
			{
				if(dp[i - 1][k] + a[i][j - k] > max_res)
				{
					max_res = dp[i - 1][k] + a[i][j - k];
					max_j = j - k;			//记录下本商店在最大利益时分配的人，注意，是j - k表示本商店的分配人数！
				}
			}
			dp[i][j] = max_res;
			path[i][j] = max_j;
		}
	}
	//打印dp数组
	cout << "dp数组为：" << endl;
	for(int i = 1;i <= m;i++)
	{
		for(int j = 0;j <= n;j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "path数组为：" << endl;
	for(int i = 1;i <= m;i++)
	{
		for(int j = 0;j <= n;j++)
		{
			cout << path[i][j] << " ";
		}
		cout << endl;
	}
	return dp[m][n];
}

int main()
{
	cout << "请输入商店个数和员工个数：";
	cin >> m >> n;
	cout << "请输入各商店分配员工数和赢利情况的表格：" << endl;
	for(int i = 1;i <= m;i++)
	{
		for(int j = 0;j <= n;j++)
		{
			cin >> a[i][j];
		}
	}
	cout << DP() << "万元" << endl;

	//输出具体方案
	cout << "具体分配方案如下：" << endl;
	cout << m << "号公司分配" << path[m][n] << "个员工" << endl;
	int r = n - path[m][n];			//剩余的人数
	for(int i = m - 1;i >= 1;i--)
	{
		cout << i << "号公司分配" << path[i][r] << "个员工" << endl;
		r = r - path[i][r];
	}
	return 0;
}
