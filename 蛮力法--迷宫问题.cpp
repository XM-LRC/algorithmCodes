#include <iostream>
using namespace std;
#define MAxN 10
int n = 8;

// �����Թ�
char MiGong[MAxN][MAxN] = {
{'o','x','x','x','x','x','x','x'},
{'o','o','o','o','o','x','x','x'},
{'x','o','x','x','o','o','o','x'},
{'x','o','x','x','o','x','x','o'},
{'x','o','x','x','x','x','x','x'},
{'x','o','x','x','o','o','o','x'},
{'x','o','o','o','o','x','o','o'},
{'x','x','x','x','x','x','x','o'}
};

// ��ӡ·��
void show(){
	for(int i = 0; i < n; i++){
		cout << " ";
		for(int j = 0; j < n; j++)
			cout << MiGong[i][j]<<" ";
		cout << endl;
	}
}

int h[4] = {0, 1, 0, -1};    //ˮƽƫ����
int v[4] = {-1, 0, 1, 0};    // ��ֱƫ����


// ������ȵķ�������·��
void DFS(int x, int y)
{
	if(x == n -1 && y == n -1)
    {
		MiGong[n - 1][n -1]= ' ';
		show();
		return;
	}else
	{    // �жϣ�x,y)���ĸ�����
		for(int k = 0; k < 4; k++){
			if(x >= 0 && y >= 0 && x < n && y < n && MiGong[x][y] == 'o') // �ж��Ƿ����
			{
				MiGong[x][y] = ' ';      // ������ԣ���������Ϊ' '��ʾ������
				DFS(x + h[k], y + v[k]); // ����(x, y)��Χ�ĸ���
				MiGong[x][y] = 'o';      // �����ڸ��ӳ���û���ҵ�·�����ָ�(x, y)Ϊ��0������ʾ����
			}
		}
	}
}

int main(){
	cout << " �Թ����£�" << endl;
	show();
	cout<<"\n�Թ�·��:"<<endl;
	DFS(0, 0);
	return 0;
}
