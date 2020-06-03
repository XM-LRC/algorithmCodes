/**
��������������⡣ũ����nͷţ��
ÿͷţ����һ���ض���ʱ������[b��e]�������Ｗţ�̣�
����һ���������κ�ʱ��ֻ����һͷţ���̡�
����ũ����ϣ��֪���������ö��ٸ������ܹ���������Ҫ��
������ÿͷţ�����ŵķ��������ڶ��ֿ��з��������һ�ּ��ɡ�

*/


#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define MAXN 20
struct Cow
{
    int no;  // ţ�ı��
    int b;   // ��ʼʱ��
    int e;
    bool operator<(const Cow &s)const
    {
        if(e==s.e)
            return b<=s.b;   // �������ʱ����ͬ����ʼʱ�����
        else
            return e<=s.e;   // ����ʱ���������
    }
};

int n=5;
Cow A[]={{0},{1,2,3},{2,3,4},{3,5,6},{4,7,8},{5,8,10}};

int ans[MAXN];   // ��Ž�����

void solve()
{
    sort(A+1,A+n+1);
    memset(ans,0,sizeof(ans));   // ��ʼ��������
    int num=1;                   // num��ʾ����������

    for(int i=1;i<=n;i++)
    {
        if(ans[i]==0)
        {
            ans[i]=num;          // num��ʾ����������
            int preend=A[i].e;   // ��������ʱ��
            for(int j=i+1;j<=n;j++)
            {
                if(A[j].b>preend&&ans[j]==0)
                {
                    ans[j]=num;
                    preend=A[j].e;
                }

            }
            num++;
        }
    }
    cout<<"����������Ϊ:"<<num<<endl;
}

int main()
{
    solve();
    return 0;
}
