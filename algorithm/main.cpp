#include<iostream>
#include<algorithm>
#include<queue>
#define MAX 100
#define INF 65535
using namespace std;


int cost[MAX];                 //源点到顶点的距离
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


// 创建有向图
void createGraph(graph g){
    cout<<"输入顶点和边数:"<<endl;
    cin>>g->vexNUM>>g->edgeNum;
    cout<<"输入顶点值:"<<endl;
    for(int i = 1;i<=g->vexNUM;i++){
         cin>>g->vex[i];
    }


    //初始化变得权值
    for(int i = 1;i<=g->vexNUM;i++){
        for(int j = 1;j<=g->vexNUM;j++){
            g->edgeWeigh[i][j] = INF;
        }
    }


    cout<<"输入边的和权值:"<<endl;
    int left,right,weight;
    for(int i = 1;i<=g->edgeNum;i++){
        cin>>left>>right>>weight;
        g->edgeWeigh[left][right] = weight;
    }
}



void  fun(graph g,int start){    // start 表示源点
      cost[start] = 0;

      for(int i = 2;i<=g->vexNUM;i++){
          cost[i] = g->edgeWeigh[start][i];
      }


      priority_queue<int,vector<int>,cmp> p;      //优先队列
      p.push(start);                              //源点入队列
      int flag [MAX];                           //顶点的出队顺序
      int k = 0;

      // 队列不为空
      while(!p.empty()){
          int e = p.top();  //出队
          flag[k++] = e;
          p.pop();

          for(int i = e;i<=g->vexNUM;i++){
             if((g->edgeWeigh[e][i]!=INF)&&(cost[e]+g->edgeWeigh[e][i]<=cost[i])){
                  cost[i] = cost[e]+g->edgeWeigh[e][i];   //更新cost
                  p.push(i);
             }
          }
      }
      for(int i = 2;i<=g->vexNUM;i++){
          cout<<start<<"到"<<i<<"顶点的最短距离为:"<<cost[i]<<endl;
      }

}
int main(){

     Graph graph;
     createGraph(&graph);
     cout<<"最短路径为:\n"<<endl;
     fun(&graph,1);
}
