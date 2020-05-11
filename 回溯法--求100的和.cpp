#include<iostream>
using namespace std;
 int N = 9;


void dis(int *a,int i,char *op,int preadd,int sum)
{

    if (sum==100)		  //找到一个解
      {  printf("%d",a[0]);	  //输出解
         for (int j=1;j<N;j++)
         {  if (op[j]!=' ')
		printf("%c",op[j]);
            printf("%d",a[j]);
         }
         printf("=100\n");
      }

}

void dfs(int *a,int i,char *op,int preadd,int sum)
{
    if(i==N)
        dis(a,i,op,preadd,sum);
    else
    {
        op[i]='+';
        sum+=a[i];
        dfs(a,i+1,op,a[i],sum);
        sum-=a[i];

        op[i]='-';
        sum-=a[i];
        dfs(a,i+1,op,-a[i],sum);
        sum+=a[i];

        op[i]=' ';
        int t;
        sum-=preadd;
        if(preadd>0)
            t=preadd*10+a[i];
        else
            t=preadd*10-a[i];
        sum+=t;
        dfs(a,i+1,op,t,sum);
        sum-=t;
        sum+=preadd;
    }
}

int main()
{
    char op[N];
    int a[N]={1,2,3,4,5,6,7,8,9};
    dfs(a,1,op,a[0],a[0]);
    return 0;
}
