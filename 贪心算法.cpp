/*
假设有一个需要使用某一资源的n个活动所组成的集合S，S={1，…，n}。
该资源任何时刻只能被一个活动所占用，
活动i有一个开始时间bi和结束时间ei（bi<ei），
其执行时间为ei-bi，假设最早活动执行时间为0。
一旦某个活动开始执行，中间不能被打断，
直到其执行完毕。若活动i和活动j有bi≥ej或bj≥ei，
则称这两个活动兼容(相容）。
设计算法求一种最优活动安排方案，使得所有安排的活动个数最多。
*/
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 20
struct Action
{
    int b;//开始时间
    int e;//结束时间
    bool operator<(const Action &s) const	//重载<关系函数
   {
	return e<=s.e;		//按结束时间构成小根堆
   }

};

int n=11;
 Action A[]={
         {0,0},{1,4},{3,5},{0,6},{5,7}
        ,{3,8},{5,9},{6,10},{8,11},{8,12}
        ,{2,13},{12,15}
	       };	//下标0不用
//求解结果表示
int flag[MAX] = {0};		//标记选择的活动
int Count=0;


void solve()				//求解最大兼容活动子集
{  memset(flag,0,sizeof(flag));	//初始化为false
   sort(A+1,A+n+1);			//A[1..n]按活动结束时间递增排序
   int preend=0;			//前一个兼容活动的结束时间
   for (int i=1;i<=n;i++)		//扫描所有活动
   {  if (A[i].b>=preend)		//找到一个兼容活动
      {  flag[i]=1;		//选择A[i]活动
         preend=A[i].e;		//更新preend值
      }
   }
}

void show(){
    cout<<"可以安排的事物如下:"<<endl;
    for (int i = 1;i <= n;i++){
        if (flag[i] == 1)
            cout<<i<<" ";
    }

}

int main()
{
    solve();
    show();
    return 0;
}






