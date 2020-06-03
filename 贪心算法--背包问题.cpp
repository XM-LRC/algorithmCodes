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
int n=5;            // 商品个数
double W=100;		// 限重
struct NodeType
{  double w;
   double v;
   double p;        // 单位最大价值
   bool operator<(const NodeType &s) const
   {
	return p>s.p;	// 按p递减排序
   }
};


NodeType A[]={{0},{10,20},{20,30},{30,66},{40,40},{50,60}};
//求解结果表示
double V = 0;	  // 最大价值
double x[MAXN];   // 解向量


/**************求解背包问题并返回总价值**************/
void Knap()
{
   double weight=W;		     // 背包中能装入的余下重量
   memset(x,0,sizeof(x));	 // 初始化x向量
   int i=1;
   while (A[i].w<weight)	 // 物品i能够全部装入时循环
   {  x[i]=1;			     // 装入物品i，保存到解向量
      weight-=A[i].w;		 // 减少背包中能装入的余下重量
      V+=A[i].v;		     // 累计总价值
      i++;			         // 继续循环
   }
   if (weight>0)		//当余下重量大于0
   {  x[i]=weight/A[i].w;	//将物品i的一部分装入
      V+=x[i]*A[i].v;		//累计总价值
   }
}

void displ(NodeType A[],int n)
{
    for (int i = 1;i <= n; i++)
        cout<<A[i].p<<"  ";
}

int main()
{

    // 求单位最大价值
   for (int i=1;i<=n;i++)
    A[i].p=A[i].v/A[i].w;
   printf("排序前\n");
   sort(A+1,A+n+1);
   displ(A,n);
   printf("\n排序后\n");
   displ(A,n);
   // 调用贪心函数
   Knap();
   printf("\n求解结果\n");
   printf("x: [");
   for (int j=1;j<=n;j++)
      printf("%g, ",x[j]);
   printf("%g]\n",x[n]);
   printf("总价值=%g\n",V);
}

