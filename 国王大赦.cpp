#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    int n;
    cout<<"����n����ʾ�ŵ�����:";
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++)
        a[i]=1;
    for(int j=2;j<=n;j++)
        for(int k=j;k<=n;)
        {
            a[k]=-a[k];
            k+=j;
        }

    for(int i=1;i<=n;i++)
        if(a[i]==1)
        cout<<"��"<<i<<"���ſ���"<<endl;
    return 0;
}
