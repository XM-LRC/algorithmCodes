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
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX 20
struct Action
{
    int b;//��ʼʱ��
    int e;//����ʱ��
    bool operator<(const Action &s) const	//����<��ϵ����
   {
	return e<=s.e;		//������ʱ�乹��С����
   }

};

int n=11;
 Action A[]={
         {0,0},{1,4},{3,5},{0,6},{5,7}
        ,{3,8},{5,9},{6,10},{8,11},{8,12}
        ,{2,13},{12,15}
	       };	//�±�0����
//�������ʾ
int flag[MAX] = {0};		//���ѡ��Ļ
int Count=0;


void solve()				//��������ݻ�Ӽ�
{  memset(flag,0,sizeof(flag));	//��ʼ��Ϊfalse
   sort(A+1,A+n+1);			//A[1..n]�������ʱ���������
   int preend=0;			//ǰһ�����ݻ�Ľ���ʱ��
   for (int i=1;i<=n;i++)		//ɨ�����л
   {  if (A[i].b>=preend)		//�ҵ�һ�����ݻ
      {  flag[i]=1;		//ѡ��A[i]�
         preend=A[i].e;		//����preendֵ
      }
   }
}

void show(){
    cout<<"���԰��ŵ���������:"<<endl;
    for (int i = 1;i <= n;i++){
        if (flag[i] == 1)
            cout<<i<<" ";
    }

}

int main()
{
    solve();
    show();
    return 0;
}






