#include<iostream>
#include<stdlib.h>
using namespace std;
int fun(int *a,int n)
{
    int max=0,thismax=0;
    int i;
    for(i=0;i<n;i++)
    {
        thismax+=a[i];
        if(thismax<0)
            thismax=0;
        if(max<thismax)
            max=thismax;
    }
    return max;
}

int main()
{
    cout<<"�����еĸ���:";
    int n;
    cin>>n;
    cout<<"����"<<n<<"��������:";
    int *a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"�����е�����:"<<fun(a,n)<<endl;
    return 0;
}
