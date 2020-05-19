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
#include<string>
#include<algorithm>
using namespace std;
struct Action
{
    int b;//开始时间
    int e;//结束时间
    bool operator<(const Action &s) const	//重载<关系函数
   {
	return e<=s.e;		//按结束时间构成小根堆
   }

};

void solve(struct &a,int &flag,int n)
{
    memset(flag,0,n);
    sort(a+1,a+1+n);
    int pree=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].b>pree)
        {
            flag[i]=1;
            pree=a[i].e;
        }
    }
}







