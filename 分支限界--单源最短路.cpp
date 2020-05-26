#include<iostream>
#include<queue>
#define INF 0x3f3f3f3f  //表示∞
#define MAX_VERTEX_NUM 30
using namespace std;


int vertexNum = 3;			//图顶点个数
int edgeArray[MAX_VERTEX_NUM][MAX_VERTEX_NUM] =
{
    { 0,  2,  5},
    {INF, 0,  1},
    {INF,INF, 0}
};
int start;	// 源点


//求解结果表示
int dist[MAX_VERTEX_NUM];        	//dist[i]: 源点到顶点i的最短路径长度
int preVertxe[MAX_VERTEX_NUM];	//preVertxe[i]:表示源点到j的最短路径中顶点j的前驱顶点

struct NodeType	//队列结点类型
{  int vno;		//顶点编号
   int length;		//路径长度
};


void bfs(int start)			//求解算法
{  NodeType e,e1;
   queue<NodeType> pqu;
   e.vno=start;				//建立源点结点e（根结点）
   e.length=0;
   pqu.push(e);			    // 源点结点e进队
   dist[start]=0;
   while(!pqu.empty())
   {  e=pqu.front(); pqu.pop();	     //出队列结点e
      for (int j=0; j<vertexNum; j++)
      {  if(edgeArray[e.vno][j]<INF && e.length+edgeArray[e.vno][j]<dist[j])
         {
            dist[j]=e.length+edgeArray[e.vno][j];  // 更新长度
            preVertxe[j]=e.vno;
            e1.vno=j;		    // 建立相邻顶点j的结点e1
            e1.length=dist[j];
            pqu.push(e1);		// 结点e1进队
         }
      }
  }
}

int main()
{
    bfs(0);
    for (int i = 1;i < vertexNum;i++){
        cout<<preVertxe[i]<<"->";
    }
}
