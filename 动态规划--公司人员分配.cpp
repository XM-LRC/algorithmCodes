/*
3 5
0 3 7 9 12 13
0 5 10 11 11 11
0 4 6 11 12 12
*/
#include<iostream>
using namespace std;

const int m = 3, n = 5;	 // mΪ�̵������nΪԱ������

int dp[m+1][n+1];       // dp[i][j]��ʾǰi����˾ʹ��j��Ա���������

//����Ա������Ӯ������ı�
 int a[m+1][n+1] =
{
    {0,3, 7, 9,12,13},
    {0,5,10,11,11,11},
    {0,4, 6,11,12,12}
};

int path[m+1][n+1];		//�洢·������¼������

int DP()
{
	// ���ݷ���dp����ʼ���߽�
	for(int i = 1;i <= m;i++)
	{
		dp[i][0] = 0;
		path[i][0] = 0;
	}

	// ����1����˾��ʼ��
	for(int j = 1;j <= n;j++)
	{
		dp[1][j] = a[1][j]; // ��1����˾�����
		path[1][j] = j;
	}

	// ������˾
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
