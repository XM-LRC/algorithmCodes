#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 100
#define INF 65535
using namespace std;


int cost[MAX];                 //Դ�㵽����ľ���
typedef struct{
    bool operator()(int &a,int &b){
         return cost[a]>cost[b];
    }
}cmp;


typedef struct Graph{
    int vexNUM,edgeNum;
    int vex[MAX];
    int edgeWeigh[MAX][MAX];
}Graph,*graph;


// ��������ͼ
void createGraph(graph g){
    cout<<"���붥��ͱ���:"<<endl;
    cin>>g->vexNUM>>g->edgeNum;
    cout<<"���붥��ֵ:"<<endl;
    for(int i = 1;i<=g->vexNUM;i++){
         cin>>g->vex[i];
    }


    //��ʼ�����Ȩֵ
    for(int i = 1;i<=g->vexNUM;i++){
        for(int j = 1;j<=g->vexNUM;j++){
            g->edgeWeigh[i][j] = INF;
        }
    }


    cout<<"����ߵĺ�Ȩֵ:"<<endl;
    int left,right,weight;
    for(int i = 1;i<=g->edgeNum;i++){
        cin>>left>>right>>weight;
        g->edgeWeigh[left][right] = weight;
    }
}



void  fun(graph g,int start){    // start ��ʾԴ��
      cost[start] = 0;

      for(int i = 2;i<=g->vexNUM;i++){
          cost[i] = g->edgeWeigh[start][i];
      }


      priority_queue<int,vector<int>,cmp> p;      //���ȶ���
      p.push(start);                              //Դ�������
      int flag [MAX];                           //����ĳ���˳��
      int k = 0;

      // ���в�Ϊ��
      while(!p.empty()){
          int e = p.top();  //����
          flag[k++] = e;
          p.pop();

          for(int i = e;i<=g->vexNUM;i++){
             if((g->edgeWeigh[e][i]!=INF)&&(cost[e]+g->edgeWeigh[e][i]<=cost[i])){
                  cost[i] = cost[e]+g->edgeWeigh[e][i];   //����cost
                  p.push(i);
             }
          }
      }
      for(int i = 2;i<=g->vexNUM;i++){
          cout<<start<<"��"<<i<<"�������̾���Ϊ:"<<cost[i]<<endl;
      }

}
int main(){

     Graph graph;
     createGraph(&graph);
     cout<<"���·��Ϊ:\n"<<endl;
     fun(&graph,1);
}
