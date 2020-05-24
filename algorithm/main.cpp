/********************************************************************
@Author�����F�
@Date�� 2020-05-23
@DescriptioN��
     ����ͼ�Ĳ���
 ��������ͼ��G=��V��E��
 V={A,B,C,D,E,F},E={(A,C,5),(A,D,1),(A,F,2),(B,D,3),(C,D,4),(C,E,7),(D,E,1),(E,F,2)}
��1������һ����ͨ������ͼ�����ϵ�Ȩ��������������ʾĳ�ִ��ۣ���
��2�����������ͼ����ʵʩ��Ȼ������ȱ�����
��3�������������ͼ��һ����С������������ķ���ߵϽ�˹��������


*********************************************************************/

#include <iostream>
#include<stdlib.h>
using namespace std;
#define MAX_NUM 10
#define INFINITY 65535
// ����ȫ�ֱ���
int visited[MAX_NUM] = {0}; // ��visited[i] = 1��ʾ���ʹ���0��ʾδ����
/********************************************************************
@FuNctioN����������ͼ�Ľṹ
@Parm: MAX_NUMVeertex ������Ŀ
@Parm��MAX_NUMEdge �ߵ���Ŀ
@Parm��vertexArray[MAX_NUM]�����
@Parm��edgeArray[MAX_NUM][MAX_NUM]���Ȩֵ�ı߱�

*********************************************************************/
typedef struct{
    int MAX_NUMVertex;
    int MAX_NUMEdge;
    char vertexArray[MAX_NUM];
    int edgeArray[MAX_NUM][MAX_NUM];
}graphType;
/********************************************************************
@Function��ʹ���ڽӾ��󴴽�����ͼ
@Parm: graph ����ͼ�ṹָ��

*********************************************************************/
void graphCreate(graphType *graph){
    int edgeLeft,edgeRight,weight;  // ��������ı��Լ�Ȩֵ�ı���
    cout<<"�����붥����=";
    cin>>graph->MAX_NUMVertex;
    cout<<"���������=";
    cin>>graph->MAX_NUMEdge;
    cout<<"������"<<graph->MAX_NUMVertex<<"������:";
    for (int i = 0;i < graph->MAX_NUMVertex;i++){
        scanf("%c",&graph->vertexArray[i]);
    }
    // ��ʼ���߱�
    for (int i = 0;i<graph->MAX_NUMEdge;i++){
        for (int j = 0;j<graph->MAX_NUMEdge;j++)
            graph->edgeArray[i][j] = INFINITY;
    }
    // �û������
    cout<<"�������[i][j]���Լ�����Ȩֵ:";
    for (int k = 0;k < graph->MAX_NUMEdge;k++){
        cin>>edgeLeft>>edgeRight>>weight;
        graph->edgeArray[edgeLeft][edgeRight] = weight;
    }
}

/********************************************************************
@Function��������ȱ�������ͼ
@Parm: graph ����ͼ�ṹָ��
*********************************************************************/
void DFS(graphType *graph,int vertex){
    visited[vertex] = 1;
    cout<<graph->vertexArray[vertex]<<"->";
    for (int j = 0;j < graph->MAX_NUMVertex;j++){
        if (graph->edgeArray[vertex][j] != INFINITY && visited[j] != 1){
            DFS(graph,j); // ������ڱ���δ������,��ݹ����
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
