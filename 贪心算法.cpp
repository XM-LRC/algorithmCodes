/*
������һ����Ҫʹ��ĳһ��Դ��n�������ɵļ���S��S={1������n}��
����Դ�κ�ʱ��ֻ�ܱ�һ�����ռ�ã�
�i��һ����ʼʱ��bi�ͽ���ʱ��ei��bi<ei����
��ִ��ʱ��Ϊei-bi����������ִ��ʱ��Ϊ0��
һ��ĳ�����ʼִ�У��м䲻�ܱ���ϣ�
ֱ����ִ����ϡ����i�ͻj��bi��ej��bj��ei��
��������������(���ݣ���
����㷨��һ�����Ż���ŷ�����ʹ�����а��ŵĻ������ࡣ
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Action
{
    int b;//��ʼʱ��
    int e;//����ʱ��
    bool operator<(const Action &s) const	//����<��ϵ����
   {
	return e<=s.e;		//������ʱ�乹��С����
   }

};

void solve(struct &a,int &flag,int n)
{
    memset(flag,0,n);
    sort(a+1,a+1+n);
    int pree=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].b>pree)
        {
            flag[i]=1;
            pree=a[i].e;
        }
    }
}







