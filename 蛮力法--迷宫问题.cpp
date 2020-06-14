#include <iostream>
using namespace std;
#define MAxN 10
int n = 8;

// 建立迷宫
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

// 打印路径
void show(){
	for(int i = 0; i < n; i++){
		cout << " ";
		for(int j = 0; j < n; j++)
			cout << MiGong[i][j]<<" ";
		cout << endl;
	}
}

int h[4] = {0, 1, 0, -1};    //水平偏移量
int v[4] = {-1, 0, 1, 0};    // 竖直偏移量


// 深度优先的方法来求路径
void DFS(int x, int y)
{
	if(x == n -1 && y == n -1)
    {
		MiGong[n - 1][n -1]= ' ';
		show();
		return;
	}else
	{    // 判断（x,y)的四个方向
		for(int k = 0; k < 4; k++){
			if(x >= 0 && y >= 0 && x < n && y < n && MiGong[x][y] == 'o') // 判断是否可走
			{
				MiGong[x][y] = ' ';      // 如果可以，则将其设置为' '表示可以走
				DFS(x + h[k], y + v[k]); // 查找(x, y)周围的格子
				MiGong[x][y] = 'o';      // 若相邻格子出发没有找到路径，恢复(x, y)为‘0’，表示不走
			}
		}
	}
}

int main(){
	cout << " 迷宫如下：" << endl;
	show();
	cout<<"\n迷宫路径:"<<endl;
	DFS(0, 0);
	return 0;
}
