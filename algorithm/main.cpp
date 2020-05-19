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
			if(x >= 0 && y >= 0 && x < n && y < n && Maze[x][y] == 'o'){ // 若(x, y)是可以走的
				Maze[x][y] = ' '; // 将该方块迷宫置为空格
				DFS(x + h[k], y + v[k]); // 查找(x, y)周围的每一个方块
				Maze[x][y] = 'o'; // 若从该相邻方块出发没有找到路径，恢复(x, y)迷宫值
			}
		}
	}
}

int main(){
	int x = 0, y = 0;
	cout << " 迷宫的一条路径：" << endl;
	DFS(x, y);
	return 0;
}
