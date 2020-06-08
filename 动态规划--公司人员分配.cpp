/*
3 5
0 3 7 9 12 13
0 5 10 11 11 11
0 4 6 11 12 12
*/
#include<iostream>
using namespace std;

const int maxn = 100;
int m, n;					//mΪ�̵������nΪԱ������
int dp[maxn][maxn];
int a[maxn][maxn];			//����Ա������Ӯ������ı�
int path[maxn][maxn];		//�洢·������¼������

//��dp[i][j]��ʾ��ǰi���̵����j��Ա���ܻ�õ��������ֵ
int DP()
{
	//�ȴ���߽�1
	for(int i = 1;i <= m;i++)
	{
		dp[i][0] = 0;
		path[i][0] = 0;
	}
	//�߽�2
	for(int j = 1;j <= n;j++)
	{
		dp[1][j] = a[1][j];
		path[1][j] = j;
	}

	//�����������������˳����ϵ��£������ң��ǳ���˳��
	for(int i = 2;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			int max_res = 0;
			int max_j = 0;
			for(int k = 0;k <= j;k++)			//�ҳ������Ǹ�
			{
				if(dp[i - 1][k] + a[i][j - k] > max_res)
				{
					max_res = dp[i - 1][k] + a[i][j - k];
					max_j = j - k;			//��¼�±��̵����������ʱ������ˣ�ע�⣬��j - k��ʾ���̵�ķ���������
				}
			}
			dp[i][j] = max_res;
			path[i][j] = max_j;
		}
	}
	//��ӡdp����
	cout << "dp����Ϊ��" << endl;
	for(int i = 1;i <= m;i++)
	{
		for(int j = 0;j <= n;j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "path����Ϊ��" << endl;
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
	cout << "�������̵������Ա��������";
	cin >> m >> n;
	cout << "��������̵����Ա������Ӯ������ı��" << endl;
	for(int i = 1;i <= m;i++)
	{
		for(int j = 0;j <= n;j++)
		{
			cin >> a[i][j];
		}
	}
	cout << DP() << "��Ԫ" << endl;

	//������巽��
	cout << "������䷽�����£�" << endl;
	cout << m << "�Ź�˾����" << path[m][n] << "��Ա��" << endl;
	int r = n - path[m][n];			//ʣ�������
	for(int i = m - 1;i >= 1;i--)
	{
		cout << i << "�Ź�˾����" << path[i][r] << "��Ա��" << endl;
		r = r - path[i][r];
	}
	return 0;
}
