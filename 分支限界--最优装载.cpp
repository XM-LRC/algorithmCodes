#include <stdio.h>
#include <queue>
using namespace std;
#define MAX_NUM 50

int n=5;
int maxWeight=10;
int weightNum[]={0,5,2,6,4,3};

int bestw=0;           //存放最大重
int bestx[MAX_NUM];    //存放最优解的解向量
int Count=1;           //搜索空间中结点数累计

typedef struct  {
    int no;
    int level;      //层次
    int weight;     //当前结点的总重量
    int x[MAX_NUM]; // 当前结点包含的解向量
    int ub;         //上界
} NodeType;

struct Cmp
{
    bool operator()(const NodeType &s,const NodeType &t)
    {
        return (s.ub<t.ub) || (s.ub==t.ub && s.x[0]>t.x[0]);
    }
};


//计算分枝结点e的上界
void bound(NodeType &e)
{
    int level=e.level+1;
    int r=0;
    while (level<=n)
    {
        r+=weightNum[level];
        level++;
    }
    e.ub=e.weight+r;
}


void fun()
{
    NodeType e,e1,e2;
    priority_queue<NodeType,vector<NodeType>,Cmp > qu;
    e.no=Count++;      //设置结点编号
    e.level=0;       //根结点置初值,其层次计为0
    e.weight=0;
    for (int j=0; j<=n; j++)   //初始化根结点的解向量
        e.x[j]=0;
    bound(e);       //求根结点的上界
    qu.push(e);      //根结点进队

    while (!qu.empty())
    {
        e=qu.top();
        qu.pop();   //出队结点e作为当前结点

        //e是一个叶子结点
        if (e.level==n)
        {
            if ((e.weight>bestw) || (e.weight==bestw && e.x[0]<bestx[0])) //比较找最优解
            {
                bestw=e.weight;   //更新bestw
                for (int j=0;j<=e.level;j++)
                    bestx[j]=e.x[j]; //复制解向量e.x->bestx
            }
        }
        //e不是叶子结点
        else
        {
            //建立左孩子结点
            if (e.weight+weightNum[e.level+1]<=maxWeight)
            {
                e1.no=Count++;
                e1.level=e.level+1;
                e1.weight=e.weight+weightNum[e1.level];

                for (int j=0; j<=e.level; j++)
                e1.x[j]=e.x[j];
                e1.x[e1.level]=1;
                e1.x[0]++;
                bound(e1);           //求左孩子结点的上界
                qu.push(e1);         //左孩子结点进队
            }

            //建立右孩子结点
            e2.no=Count++;
            e2.level=e.level+1;
            e2.weight=e.weight;
            for (int j=0; j<=e.level; j++)
                e2.x[j]=e.x[j];
            e2.x[e2.level]=0;
            bound(e2);
            if (e2.ub>bestw)   //若右孩子结点可行,则进队,否则被剪枝
                qu.push(e2);
        }
    }
}

// 输出结果
void displ()
{
    printf("选取的重量为：  X=[ ");
    for (int i=1;i<=n;i++)
        if( bestx[i]==1 )
            printf("%d ",weightNum[i]);
    printf("]\n装载的总价值为%d\n",bestw);
}

int main()
{
    fun();
    displ();
}
