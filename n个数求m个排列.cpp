/*---------------------------------------------------------------------------

���⣺
���õݹ���ݷ����һ���㷨��
���1~n��n��������ȡ��m��Ԫ�ص�����
��Ҫ��ÿ������Ԫ��ֻ��ȡһ�Ρ�
���磺n=3��m=2���������ǣ�1,2����1,3����2,1����2,3����3,1����3,2��

----------------------------------------------------------------------------*/
#include<iostream>
using namespace std;
void fun(int n,int m,int* result,int len)
{
    if(m==0)
    {
        cout<<"( ";
        for(int i=0;i<len;i++)
            cout<<result[i]<<" ";
        cout<<" )"<<endl<<"( ";
        for(int i=len-1;i>=0;i--)
            cout<<result[i]<<" ";
        cout<<" )";
        cout<<endl;
        return;
    }
    for(int i=n;i>=m;i--)
    {
        result[m-1]=i;
        fun(i-1,m-1,result,len);
    }
}

int main()
{
    int n,m;
    cout<<"n=";
    cin>>n;
    cout<<"m=";
    cin>>m;
    int a[2];
    fun(n,m,a,m);
    return 0;
}
