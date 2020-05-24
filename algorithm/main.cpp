/********************************************************************
@Author：林镕琛
@Date： 2020-05-23
@DescriptioN：
     无向图的操作
 给定无向图：G=（V，E）
 V={A,B,C,D,E,F},E={(A,C,5),(A,D,1),(A,F,2),(B,D,3),(C,D,4),(C,E,7),(D,E,1),(E,F,2)}
（1）创建一个连通的无向图（边上的权都是正整数，表示某种代价）；
（2）对这个无向图可以实施深度或广度优先遍历；
（3）求这个无向网图的一棵最小生成树（普利姆或者迪杰斯克拉）。


*********************************************************************/

#include <iostream>
#include<stdlib.h>
using namespace std;
#define MAX_NUM 10
#define INFINITY 65535
// 定义全局变量
int visited[MAX_NUM] = {0}; // 当visited[i] = 1表示访问过，0表示未访问
/********************************************************************
@FuNctioN：创建无向图的结构
@Parm: MAX_NUMVeertex 顶点数目
@Parm：MAX_NUMEdge 边的数目
@Parm：vertexArray[MAX_NUM]顶点表
@Parm：edgeArray[MAX_NUM][MAX_NUM]存放权值的边表

*********************************************************************/
typedef struct{
    int MAX_NUMVertex;
    int MAX_NUMEdge;
    char vertexArray[MAX_NUM];
    int edgeArray[MAX_NUM][MAX_NUM];
}graphType;
/********************************************************************
@Function：使用邻接矩阵创建无向图
@Parm: graph 无向图结构指针

*********************************************************************/
void graphCreate(graphType *graph){
    int edgeLeft,edgeRight,weight;  // 定义输入的边以及权值的变量
    cout<<"请输入顶点数=";
    cin>>graph->MAX_NUMVertex;
    cout<<"请输入边数=";
    cin>>graph->MAX_NUMEdge;
    cout<<"请输入"<<graph->MAX_NUMVertex<<"个顶点:";
    for (int i = 0;i < graph->MAX_NUMVertex;i++){
        scanf("%c",&graph->vertexArray[i]);
    }
    // 初始化边表
    for (int i = 0;i<graph->MAX_NUMEdge;i++){
        for (int j = 0;j<graph->MAX_NUMEdge;j++)
            graph->edgeArray[i][j] = INFINITY;
    }
    // 用户输入边
    cout<<"请输入边[i][j]，以及它的权值:";
    for (int k = 0;k < graph->MAX_NUMEdge;k++){
        cin>>edgeLeft>>edgeRight>>weight;
        graph->edgeArray[edgeLeft][edgeRight] = weight;
    }
}

/********************************************************************
@Function：深度优先遍历无向图
@Parm: graph 无向图结构指针
*********************************************************************/
void DFS(graphType *graph,int vertex){
    visited[vertex] = 1;
    cout<<graph->vertexArray[vertex]<<"->";
    for (int j = 0;j < graph->MAX_NUMVertex;j++){
        if (graph->edgeArray[vertex][j] != INFINITY && visited[j] != 1){
            DFS(graph,j); // 如果存在边且未被访问,则递归遍历
        }
    }
}

void deepFirstTraversal(graphType *graph){
    for (int i = 0;i < graph->MAX_NUMVertex;i++){
        if(visited[i] != 1){
            DFS(graph,i);
        }
    }
}
int main()
{
    graphType *graph;
    graphCreate(graph);
    deepFirstTraversal(graph);
    return 0;
}
