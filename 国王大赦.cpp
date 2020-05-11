#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    int n;
    cout<<"输入n来表示门的数量:";
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
        cout<<"第"<<i<<"个门开着"<<endl;
    return 0;
}
