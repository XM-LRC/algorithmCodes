#include <iostream>
using namespace std;

#define MAxN 10
int n = 8;
char Maze[MAxN][MAxN] = {
{'o','x','x','x','x','x','x','x'},
{'o','o','o','o','o','x','x','x'},
{'x','o','x','x','o','o','o','x'},
{'x','o','x','x','o','x','x','o'},
{'x','o','x','x','x','x','x','x'},
{'x','o','x','x','o','o','o','x'},
{'x','o','o','o','o','x','o','o'},
{'x','x','x','x','x','x','x','o'}
};

void disppath(){
	for(int i = 0; i < n; i++){
		cout << " ";
		for(int j = 0; j < n; j++)
			cout << Maze[i][j];
		cout << endl;
	}
}

int h[4] = {0, 1, 0, -1};
int v[4] = {-1, 0, 1, 0};

void DFS(int x, int y){
	if(x == n -1 && y == n -1){
		Maze[n - 1][n -1]= ' ';
		disppath();
		return;
	}else{
		for(int k = 0; k < 4; k++){
			if(x >= 0 && y >= 0 && x < n && y < n && Maze[x][y] == 'o'){ // ��(x, y)�ǿ����ߵ�
				Maze[x][y] = ' '; // ���÷����Թ���Ϊ�ո�
				DFS(x + h[k], y + v[k]); // ����(x, y)��Χ��ÿһ������
				Maze[x][y] = 'o'; // ���Ӹ����ڷ������û���ҵ�·�����ָ�(x, y)�Թ�ֵ
			}
		}
	}
}

int main(){
	int x = 0, y = 0;
	cout << " �Թ���һ��·����" << endl;
	DFS(x, y);
	return 0;
}
