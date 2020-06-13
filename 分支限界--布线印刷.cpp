#include <iostream>
#include <queue>
using namespace std;
int m=8;
int n=8;
int grid[10][10];   // 二维方格子
int indexcount=0;

struct Position
{
    int row;   // 行
    int col;   // 列
};

// 用于显示格子情况
void showPath()
{
    for(int i=0; i<10; i++)
    {

        for(int j=0; j<10; j++)
            cout<<grid[i][j]<<"  ";
        cout<<endl;
    }
    cout<<"------------------"<<endl;
}
bool FindPath(Position start,Position finish,int &PathLen,Position  *&path)
{
    // 计算从起点位置start到目标位置finish的最短布线路径，
    // 找到最短布线路径则返回true，否则返回false

    if((start.row==finish.row) && (start.col==finish.col))
    {
        PathLen=0;
        cout<<"start=finish"<<endl;
        return true;
    }

    //初始化图，-1为未访问
    for(int i=1; i<9; i++)
    {
        for(int j=1; j<9; j++)
            grid[i][j]=-1;

    }
    // 设置被阻挡的格子
     grid[2][3]=-2;
    for(int i=0; i<= m+1; i++)
        grid[0][i]=grid[n+1][i]=-2; //顶部和底部
    for(int i=0; i<= n+1; i++)
        grid[i][0]=grid[i][m+1]=-2; //左翼和右翼

    Position offset[4];
    offset[0].row=0;
    offset[0].col=1;//右
    offset[1].row=1;
    offset[1].col=0;//下
    offset[2].row=0;
    offset[2].col=-1;//左
    offset[3].row=-1;
    offset[3].col=0;//上
    int NumOfNbrs=4;//相邻方格数
    Position here,nbr;
    here.row=start.row;
    here.col=start.col;
    grid[start.row][start.col]=0;
    //标记可达方格位置
    cout<<"布线前图"<<endl;
    showPath();

    queue<Position> Q;
    do  //标记相邻可达方格
    {
        for(int I=0; I<NumOfNbrs; I++)
        {
            nbr.row=here.row + offset[I].row;
            nbr.col=here.col+offset[I].col;
            if(grid[nbr.row][nbr.col]==-1)
            {
             //该方格未被标记
                grid[nbr.row][nbr.col]=grid[here.row][here.col]+1;
            }
            if((nbr.row==finish.row) &&(nbr.col==finish.col)) break; //完成布线
            Q.push(nbr);
        }
         //是否到达目标位置finish？
        if((nbr.row==finish.row)&&(nbr.col==finish.col)) break;//完成布线
        if(Q.empty()) return false;//无解
        here = Q.front();
        Q.pop();//取下一个扩展结点
        indexcount++;
    }
    while(true);
    PathLen=grid[finish.row][finish.col];
    path=new Position[PathLen];
    //从目标位置finish开始向起始位置回溯
    here=finish;
    for(int j=PathLen-1; j>=0; j--)
    {
        path[j]=here;
     // 找前驱位置
        for(int i=0; i<NumOfNbrs; i++)
        {
            nbr.row=here.row+offset[i].row;
            nbr.col=here.col+offset[i].col;
            if(grid[nbr.row][nbr.col]==j)
            {
               // cout<<j<<endl;
                break;
            }
        }
        here=nbr;//向前移动
    }
    return PathLen;
}
int main()
{
    Position start;
    start.col=1;
    start.row=1;
    cout<<"布线的起始位置坐标"<<endl;
    cout<<start.col<<" "<<start.row<<endl;
    Position finish;
    finish.row=3;
    finish.col=4;
     cout<<"布线位置坐标"<<endl;
      cout<<finish.col<<" "<<finish.row<<endl;
    int PathLen=0;
    Position *path;
    FindPath(start,finish,PathLen,path);
    cout<<"布线后路径图"<<endl;
    showPath();
    cout<<"最短路径是："<<endl;
    for(int i=0; i<PathLen; i++)
    {
        cout<<path[i].col<<" "<<path[i].row<<endl;
    }
    return 0;
}
