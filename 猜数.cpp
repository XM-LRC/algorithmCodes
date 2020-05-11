#include<iostream>
using namespace std;

void GetXiShu(int *c,int a,int b,int d,int *x)
{
    for(c[0]=1;c[0]<100;c[0]++)
        for(c[1]=1;c[1]<100;c[1]++)
            for(c[2]=1;c[2]<100;c[2]++)
                if(c[0]%a==1&&c[1]%a==0&&c[2]%a==0
                   &&c[1]%b==1&&c[0]%b==0&&c[2]%b==0
                   &&c[2]%d==1&&c[0]%d==0&&c[1]%d==0)
            {
                cout<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
                x[0]=c[0];
                x[1]=c[1];
                x[2]=c[2];
                break;
            }
}

int GBS(int a,int b, int c)
{
    int m=a>b? (a>c? a:c):(b>c? b:c);
    while((m%a !=0) || (m%b!=0) || (m%c!=0))
        m++;
    return m;
}

int main()
{
    int c[3]={1,1,1};
    int n[3]={1,1,1};
    int x,y,z,a,b,d;
    cout<<"输入除数:";
    cin>>x>>y>>z;
    cout<<"输入余数:";
    cin>>a>>b>>d;
    int gbs=GBS(x,y,z);
    GetXiShu(c,x,y,z,n);
    cout<<n[0]<<" "<<n[1]<<" "<<n[2]<<endl;
    int m = n[0]*a+n[1]*b+n[2]*d;
    while(m>100)
        m=m-gbs;
    cout<<"这个数是:"<<m;

}
