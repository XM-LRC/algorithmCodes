/**
����Ҫ���㹻��᳡�ﰲ��һ�����n������Ϊ1~n��
ÿ����п�ʼʱ��bi�ͽ���ʱ��ei��1<=i<=n����
���һ����Ч��̰���㷨������ٵĻ᳡������

*/


#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAXN 20
struct Activity
{
    int no;  // ����
    int b;   // ��ʼʱ��
    int e;   // ����ʱ��

    // �¼���ʱ���ǲ����ݵ�
    bool operator<(const Activity &s)const
    {
        if(e==s.e)
            return b<=s.b;   // �������ʱ����ͬ����ʼʱ�����
        else
            return e<=s.e;   // ����ʱ���������
    }
};

int n=5;
Activity A[]={{0},{1,2,3},{2,3,4},{3,5,6},{4,7,8},{5,8,10}};

int x[MAXN];   // ��Ž�����

void solve()
{
    sort(A+1,A+n+1);
    memset(x,0,sizeof(x));    // ��ʼ��������
    int num=1;                // num��ʾ�᳡����

    for(int i=1;i<=n;i++)
    {
        if(x[i]==0)
        {
            x[i]=1;            // ��ӵ�������
            int preend=A[i].e; // ��������ʱ��
            for(int j=i+1;j<=n;j++)
            {
                if(A[j].b>preend&&x[j]==0)
                {
                    x[j]=num;
                    preend=A[j].e;
                }

            }
            num++;
        }
    }
    cout<<"���ٻ᳡������Ϊ:"<<num<<endl;
}

int main()
{
    cout<<"���������µ�"<<n<<"���"<<endl;
    cout<<"���   "<<"��ʼʱ��"<<"\t\t����ʱ��"<<endl;
    for (int i =1;i <= n;i++){
        cout<<A[i].no<<"\t"<<A[i].b<<"\t\t"<<A[i].e<<endl;
    }
    cout<<endl;
    solve();
    return 0;
}
