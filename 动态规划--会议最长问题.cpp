/*
���鰲������:һ��������ĳһʱ��ֻ�ܰ���һ�����飬
����n���������룬ÿ�����������ʼʱ��ͽ���ʱ�䣬
������û����Ҽ��ݻ������ʱ����Ļ��鰲�ŷ���
������ʹ�û�����ʱ����Ļ��鰲�ŷ�����
���±��е������Ѿ����ս���ʱ������
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100;
struct Meeting{
	int start = 0;
	int end = 0;
};

Meeting a[MAX];    // ��Ż�����ʼʱ��
int dp[MAX];		// dp[i]Ϊǰi����ܻ�õ���ʱ��
int n;              // �������


int DP()
{
    // ��ʼ��
	dp[1] = a[1].end - a[1].start;
	for(int i = 2;i <= n;i++)
	{
		int max_res = a[i].end - a[i].start;
		for(int j = 0;j < i;j++)
		{
		    // ״̬ת�Ʒ���
			if(a[j].end <= a[i].start && dp[j] + a[i].end - a[i].start > max_res)
				max_res = dp[j] + a[i].end - a[i].start;
		}
		dp[i] = max_res;
	}
	return dp[n];
}

int main()
{
    cout<<"�������:";
	cin >> n;
	cout<<"������鿪ʼ�ͽ���ʱ��:"<<endl;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i].start >> a[i].end;
	}
	cout << "�����ʱ���ǣ�" << DP() << endl;
	return 0;
}
