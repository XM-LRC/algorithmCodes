/*
会议安排问题:一个会议室某一时刻只能安排一个会议，
现有n个会议申请，每个会议给出开始时间和结束时间，
请给出该会议室兼容会议持续时间最长的会议安排方案
——即使用会议室时间最长的会议安排方案。
（下表中的数据已经按照结束时间排序）
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100;
struct Meeting{
	int start = 0;
	int end = 0;
};

Meeting a[MAX];    // 存放会议起始时间
int dp[MAX];		// dp[i]为前i个活动能获得的最长活动时间
int n;              // 会议个数


int DP()
{
    // 初始化
	dp[1] = a[1].end - a[1].start;
	for(int i = 2;i <= n;i++)
	{
		int max_res = a[i].end - a[i].start;
		for(int j = 0;j < i;j++)
		{
		    // 状态转移方程
			if(a[j].end <= a[i].start && dp[j] + a[i].end - a[i].start > max_res)
				max_res = dp[j] + a[i].end - a[i].start;
		}
		dp[i] = max_res;
	}
	return dp[n];
}

int main()
{
    cout<<"会议个数:";
	cin >> n;
	cout<<"输入会议开始和结束时间:"<<endl;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].start >> a[i].end;
	}
	cout << "最长会议时间是：" << DP() << endl;
	return 0;
}
