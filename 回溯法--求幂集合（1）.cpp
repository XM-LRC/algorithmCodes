#include<iostream>
#include<stdlib.h>
using namespace std;

void display(int *a,int n,int *x)
{
    cout<<"{";
    for(int j=0;j<n;j++)
        if(x[j]==1)
        cout<<a[j]<<" ";
    cout<<"}"<<endl;
}


void dfs(int *a,int n,int i,int *x)
{
    if(i>=n)
        display(a,n,x);
    else
        for(int j=0;j<=1;j++)
        {
            x[i]=j;
            dfs(a,n,i+1,x);
        }
}


int main()
{
    int a[3]={1,2,3};
    int x[3];
    dfs(a,3,0,x);
    return 0;
}
