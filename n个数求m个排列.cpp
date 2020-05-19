/*---------------------------------------------------------------------------

问题：
采用递归回溯法设计一个算法，
求从1~n的n个整数中取出m个元素的排列
，要求每个数据元素只能取一次。
例如：n=3、m=2的输出结果是（1,2）（1,3）（2,1）（2,3）（3,1）（3,2）

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
