/**
求解0/1背包问题的算法
（采用的是二维数组方法）
*/
#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 20					// 最多物品数
#define MAXW 100				// 最大限制重量
//问题表示
int n=5,W=10;					// 5种物品,限制重量不超过10
int w[MAXN]={0,2,2,6,5,4};		// 下标0不用
int v[MAXN]={0,6,3,5,4,6};		// 下标0不用
//求解结果表示
int dp[MAXN][MAXW];             // 存放动态规划数组
int x[MAXN];                    // 存放解向量
int maxv; 						// 存放最优解的总价值

/************动态规划法--完成dp数组************/
void Knap()
{
	int i,r;
	for (i=0;i<=n;i++)			//置边界条件dp[i][0]=0
		dp[i][0]=0;
	for (r=0;r<=W;r++)			//置边界条件dp[0][r]=0
		dp[0][r]=0;
	for (i=1;i<=n;i++)
	{	for (r=1;r<=W;r++)
			if (r<w[i])
				dp[i][r]=dp[i-1][r];
			else
				dp[i][r]=max(dp[i-1][r],dp[i-1][r-w[i]]+v[i]);
	}
}

/*******回推求最优解，设置解向量，通过解向量定点******/
void Buildx()
{
	int i=n,r=W;                // 从最优解，逆推回来
	maxv=0;
	while (i>=0)				// 判断每个物品
	{
		if (dp[i][r]!=dp[i-1][r])
		{
			x[i]=1;				// 选取物品i
			maxv+=v[i];			// 累计总价值
			r=r-w[i];
		}
		else
			x[i]=0;				// 不选取物品i
		i--;
	}
}
int main()
{
	Knap();
	Buildx();
	printf("求解结果(最优方案)\n");		//输出结果
	printf("    选取的物品: ");
	for (int i=1;i<=n;i++)
		if (x[i]==1)
			printf("%d ",i);
	printf("\n");
	printf("    总价值=%d\n",maxv);
}
