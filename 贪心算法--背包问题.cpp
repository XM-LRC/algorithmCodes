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
int n=5;            // ��Ʒ����
double W=100;		// ����
struct NodeType
{  double w;
   double v;
   double p;        // ��λ����ֵ
   bool operator<(const NodeType &s) const
   {
	return p>s.p;	// ��p�ݼ�����
   }
};


NodeType A[]={{0},{10,20},{20,30},{30,66},{40,40},{50,60}};
//�������ʾ
double V = 0;	  // ����ֵ
double x[MAXN];   // ������


/**************��ⱳ�����Ⲣ�����ܼ�ֵ**************/
void Knap()
{
   double weight=W;		     // ��������װ�����������
   memset(x,0,sizeof(x));	 // ��ʼ��x����
   int i=1;
   while (A[i].w<weight)	 // ��Ʒi�ܹ�ȫ��װ��ʱѭ��
   {  x[i]=1;			     // װ����Ʒi�����浽������
      weight-=A[i].w;		 // ���ٱ�������װ�����������
      V+=A[i].v;		     // �ۼ��ܼ�ֵ
      i++;			         // ����ѭ��
   }
   if (weight>0)		//��������������0
   {  x[i]=weight/A[i].w;	//����Ʒi��һ����װ��
      V+=x[i]*A[i].v;		//�ۼ��ܼ�ֵ
   }
}

void displ(NodeType A[],int n)
{
    for (int i = 1;i <= n; i++)
        cout<<A[i].p<<"  ";
}

int main()
{

    // ��λ����ֵ
   for (int i=1;i<=n;i++)
    A[i].p=A[i].v/A[i].w;
   printf("����ǰ\n");
   sort(A+1,A+n+1);
   displ(A,n);
   printf("\n�����\n");
   displ(A,n);
   // ����̰�ĺ���
   Knap();
   printf("\n�����\n");
   printf("x: [");
   for (int j=1;j<=n;j++)
      printf("%g, ",x[j]);
   printf("%g]\n",x[n]);
   printf("�ܼ�ֵ=%g\n",V);
}

