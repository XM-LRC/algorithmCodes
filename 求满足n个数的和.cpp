#include<iostream>
#include<stdlib.h>
using namespace std;

void cal(int *a,int n,int *x,int K)
{
    int sum=0;
    for(int j=0;j<n;j++)
        if(x[j]==1)
        sum+=a[j];
    if(sum==K){

        for(int j=0;j<n;j++)
        if(x[j]==1)
        cout<<a[j]<<" ";
        cout<<endl;
    }
}


void dfs(int *a,int n,int i,int *x,int K)
{
    if(i>=n)
        cal(a,n,x,K);
    else
        for(int j=0;j<=1;j++)
        {
            x[i]=j;
            dfs(a,n,i+1,x,K);
        }
}


int main()
{
    cout<<"������������:";
    int K,n;
    cin>>n;
    int *a=(int *)malloc(sizeof(int )*n);
    int *x=(int *)malloc(sizeof(int )*n);
    cout<<"��������"<<n<<"������:";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"����k��ʾ����ĺͣ�k=";
    cin>>K;
    dfs(a,n,0,x,K);
    return 0;
}
