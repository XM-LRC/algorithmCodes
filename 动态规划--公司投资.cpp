/*
ĳ��Ŀ��ֵ���7��Ԫ��Ͷ�ʣ�
��Ҫ����7��Ԫ�����A��B��C��������Ŀ��
ÿ����Ŀ���������£������һ�ַ��䷽��ʹ��������󣨵�λ����Ԫ����

*/
#include<iostream>
using namespace std;
#define maxn 50


int m = 3, n = 7;	// 3����Ŀ��7��ԪͶ��
// Ͷ�������
double a[maxn][maxn] =
{
    {0,0,0,0,0,0,0},
    {0, 0.11, 0.13, 0.15, 0.21, 0.24, 0.30, 0.35},
    {0, 0.12, 0.16, 0.21, 0.23, 0.25, 0.24, 0.34},
    {0, 0.08, 0.12, 0.20, 0.24, 0.26, 0.30, 0.35}

};


double dp[maxn][maxn];	   	//��dp[i][j]��ʾ��ǰi����ĿͶ��j��Ԫ�ܻ�õ��������
double path[maxn][maxn];	//�洢·������¼Ͷ�ʽ��


double DP()
{
	// �߽紦��
	for(int i = 1;i <= m;i++)
	{
		dp[i][0] = 0;
		path[i][0] = 0;
	}
	for(int j = 1;j <= n;j++)
	{
		dp[1][j] = a[1][j];
		path[1][j] = j;
	}


	for(int i = 2;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			double max_res = 0;
			double max_j = 0;
			for(int k = 0;k <= j;k++)	//�ҳ��������
			{
				if(dp[i - 1][k] + a[i][j - k] > max_res)
				{
					max_res = dp[i - 1][k] + a[i][j - k];
					max_j = j - k;	  //��¼�¸���Ŀ���������ʱͶ�ʵ�Ǯ
					                  //���У�j - k��ʾ����ĿͶ�ʵ�Ǯ
				}
			}
			dp[i][j] = max_res;
			path[i][j] = max_j;
		}
	}
	return dp[m][n];  // �����������
}

int main()
{

	cout <<"�������:"<< DP() << "��Ԫ" << endl;

	//������巽��
	cout << "Ͷ�ʷ�����" << endl;
	cout << m << "�Ź�˾Ͷ��" << path[m][n] << "��Ԫ" << endl;
	int r = n - path[m][n];
	for(int i = m - 1;i >= 1;i--)
	{
		cout << i << "�Ź�˾Ͷ��" << path[i][r] << "��Ԫ" << endl;
		r = r - path[i][r];
	}
	return 0;
}
