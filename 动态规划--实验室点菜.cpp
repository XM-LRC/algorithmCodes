/**
某实验室经常有活动需要叫外卖，
但是每次叫外卖报销的经费总额最大为C元，
有N种菜可以点，经过长时间的点菜，
实验室对每种菜i都有一个量化的评分Vi，
这种菜的价格为Pi，问如何选择各种菜（每种菜只能点一次）
，才能在报销额度范围内使点到菜的总评价分数最高。
*/
#include <iostream>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 20					// 最多菜的品种
#define MAXW 50				// 最大的价格
//问题表示
int N=8,C=20;					 // N种物品,经费总额不超过C
int p[MAXN]={0,2,1,6,5,4,3,10,7};// 每种菜的价格，下标0不用
int v[MAXN]={0,6,3,5,4,6,5,8,6}; // 每种菜的评分，下标0不用
//求解结果表示
int dp[MAXN][MAXW];              // 存放动态规划数组
int x[MAXN];                     // 存放解向量
int maxv; 						 // 存放最优解的总价值

/************动态规划法--完成dp数组************/
void solve()
{
	int i,r;
	for (i=0;i<=N;i++)			//置边界条件dp[i][0]=0
		dp[i][0]=0;
	for (r=0;r<=C;r++)			//置边界条件dp[0][r]=0
		dp[0][r]=0;
    // 状态转换
	for (i=1;i<=N;i++)
	{	for (r=1;r<=C;r++)
			if (r<p[i])
				dp[i][r]=dp[i-1][r];
			else
				dp[i][r]=max(dp[i-1][r],dp[i-1][r-p[i]]+v[i]);
	}
}

/*******回推求最优解，设置解向量，通过解向量定点******/
void goback()
{
	int i=N,r=C;                // 从最优解开始，逆推回来
	maxv=0;
	while (i>=0)
	{
		if (dp[i][r]!=dp[i-1][r])
		{
			x[i]=1;				// 选取这样菜
			maxv+=v[i];			// 累计评分
			r=r-p[i];
		}
		else
			x[i]=0;				// 不选取这样菜
		i--;
	}
}
int main()
{
    cout<<"所有的菜品价格：";
    for (int i = 1;i <= N;i++)
        cout<<p[i]<<"  ";
    cout<<"\n所有的菜品评分：";
    for (int i = 1;i <= N;i++)
        cout<<v[i]<<"  ";
	solve();
	goback();
	printf("\n动态规划结果(最优方案)\n");		//输出结果
	printf("    选取的菜品: ");
	for (int i=1;i<=N;i++)
		if (x[i]==1)
			printf("%d ",i);
	printf("\n");
	printf("    总评分=%d\n",maxv);
}
