/*
���һ�������г��ִ�������Ԫ��
����n������������д�����ҳ������г��ִ�����������
������������ж�������������С������

*/
#include <iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
   int n;
   cout<<"�����е�Ԫ�ظ�����";
   cin>>n;
   int a[n],x[n]; // a[n]�Ǵ�����У�x[n]�����ͬԪ�صĸ���
   cout<<"������Ԫ�أ�";
   for (int i = 0; i < n ;i++)
      cin>>a[i];
   sort(a,a+n);   // ������Ԫ������


    // ��û����ʱ��x[n]�����Զ���1����ʾ����Ԫ�س���1��
    for(int i =0 ;i<n;i++)
        x[i]= 1;

   int pre = 0;
   for (int i =1 ;i < n; i++)
   {
       if (a[i] == a[pre])
       {
           x[i] = x [i] + x[pre];   // ���ǰһ��Ԫ���뵱ǰ��ͬ����ǰx[i] + 1;
           pre = i;
       }
       else {
           pre = i;
           x[pre] = 1;
       }
   }
    cout<<"�����Ԫ�أ�";
    for (int i =0;i <n;i++)
        cout<<a[i]<<"  ";
    cout<<"\n�����ִ�����";
    for(int i =0 ;i<n;i++)
        cout<<x[i]<<"  ";

    // Ѱ�ҳ��ִ���������һ�����±�
    int max=0;
    for(int i=1;i<n;i++)
    if(x[i]>x[max])
    {
        max=i;
    }

    cout<<"\n���ִ�����������: "<<a[max]<<endl;

    return 0;
}
