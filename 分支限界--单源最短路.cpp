#include<iostream>
#include<queue>
#define INF 0x3f3f3f3f  //��ʾ��
#define MAX_VERTEX_NUM 30
using namespace std;


int vertexNum = 3;			//ͼ�������
int edgeArray[MAX_VERTEX_NUM][MAX_VERTEX_NUM] =
{
    { 0,  2,  5},
    {INF, 0,  1},
    {INF,INF, 0}
};
int start;	// Դ��


//�������ʾ
int dist[MAX_VERTEX_NUM];        	//dist[i]: Դ�㵽����i�����·������
int preVertxe[MAX_VERTEX_NUM];	//preVertxe[i]:��ʾԴ�㵽j�����·���ж���j��ǰ������

struct NodeType	//���н������
{  int vno;		//������
   int length;		//·������
};


void bfs(int start)			//����㷨
{  NodeType e,e1;
   queue<NodeType> pqu;
   e.vno=start;				//����Դ����e������㣩
   e.length=0;
   pqu.push(e);			    // Դ����e����
   dist[start]=0;
   while(!pqu.empty())
   {  e=pqu.front(); pqu.pop();	     //�����н��e
      for (int j=0; j<vertexNum; j++)
      {  if(edgeArray[e.vno][j]<INF && e.length+edgeArray[e.vno][j]<dist[j])
         {
            dist[j]=e.length+edgeArray[e.vno][j];  // ���³���
            preVertxe[j]=e.vno;
            e1.vno=j;		    // �������ڶ���j�Ľ��e1
            e1.length=dist[j];
            pqu.push(e1);		// ���e1����
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
