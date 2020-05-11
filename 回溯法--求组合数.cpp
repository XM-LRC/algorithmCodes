#include<iostream>
#include<stdlib.h>
using namespace std;

void dis(int *a,int n)
{
    cout<<"{";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"}"<<endl;
}

void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void dfs(int *a,int n,int i)
{
    if(i>=n)
        dis(a,n);

    else
    for(int j=i;j<n;j++)
    {
        swap(&a[i],&a[j]);
        dfs(a,n,i+1);
        swap(&a[i],&a[j]);

    }

}


int main()
{
   int a[5]={1,2,3,4,5};
   dfs(a,5,0);
    return 0;
}
